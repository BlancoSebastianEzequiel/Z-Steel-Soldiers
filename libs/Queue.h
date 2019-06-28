// "Copyright [2017] <Copyright SebastianBlanco>"
//------------------------------------------------------------------------------
#ifndef _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONQUEUE_H_
#define _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONQUEUE_H_
//------------------------------------------------------------------------------
#include <mutex>
#include <condition_variable>
#include <queue>
//------------------------------------------------------------------------------
/*
 * Implementacion de una cola protegida (thread safe).
 * No solo los metodos push y pop usan un mutex para evitar
 * race conditions sino que ademas hacen uso de una condition variable
 * para permitir que el metodo pop se bloquee cuando la cola este vacia
 * y se despierte cuando haya algo que sacar (cola no vacia).
 *
 * Se deja al lector las siguientes posibles mejoras:
 *  - hacer que Queue sea movible (implementar el constructor y el operador
 *    asignacion por movimiento)
 *  - implementar una especializacion total Queue<void*> y luego
 *    una especializacion parcial Queue<T*> con el fin de evitar el code
 *    bloat por parte del compilador.
 **/
//------------------------------------------------------------------------------
template<class T>
class Queue {
 private :
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;
 public :
    //--------------------------------------------------------------------------
    Queue() {}
    //--------------------------------------------------------------------------
    void push(const T& val) {
        // mtx.lock() pero en modo RAII
        std::unique_lock<std::mutex> lck(mtx);
        if (q.empty()) {
            /*
             * La cola esta vacia por lo que este push hara que la cola
             * tenga un elemento y por lo tanto deje de estar vacia.
             *
             * Como puede haber hilos esperando a que la cola no este
             * vacia, despertamos a todos ellos enviandoles una señal
             * con el metodo notify_all().
             *
             * Como este hilo aun tiene adquirido el mutex (lock), los
             * otros hilos que se despierten no ejecutaran nada hasta
             * que liberemos nosotros el mutex lo que nos garantiza que no
             * habra race conditions.
             * */
            cv.notify_all();
        }
        q.push(val);
    }  // lck se destruye y automaticamente libera el mutex con mtx.unlock()
    //--------------------------------------------------------------------------
    T pop() {
        // mtx.lock() pero en modo RAII
        std::unique_lock<std::mutex> lck(mtx);
        while (q.empty()) {
            /* Si la cola esta vacia, no podemos hacer un pop.
             * En vez de retornar con un codigo de error esperamos
             * a que la cola deje de estar vacia con el metodo wait().
             *
             * Literalmente este hilo deja de ejecutarse a la espera de
             * recibir una señal.
             * Señal que deberia llegarnos cuando la cola no este vacia
             * (alguien hizo un push). Sin embargo como pueden haber
             * otros hilos tambien haciendo pop, es posible que para
             * cuando este hilo en particular se despierte la cola vuelva
             * a estar vacia: por eso tenemos un loop y mientras este
             * vacia seguiremos haciendo waits.
             *
             * Por supuesto, el metodo wait() automaticamente libera
             * el mutex asociado de otro modo ningun otro hilo podria
             * hacer el push. Cuando este hilo se despierte y se
             * retorne de wait(), el mutex es automaticamente obtenido
             * (lock) de forma transparente al desarrollador.
             *
             * Colorario: el metodo wait debe llamarse solo si el mutex ya
             * fue adquirido sino el comportamiento es indefinido
             * */
            cv.wait(lck);
        }
        const T val = q.front();
        q.pop();
        return val;
    }  // lck se destruye y automaticamente libera el mutex con mtx.unlock()
    //--------------------------------------------------------------------------
    size_t size() {
        return q.size();
    }
    //--------------------------------------------------------------------------
 private :
    //--------------------------------------------------------------------------
    Queue(const Queue&) = delete;
    //--------------------------------------------------------------------------
    Queue& operator=(const Queue&) = delete;
    //--------------------------------------------------------------------------
};
//------------------------------------------------------------------------------
#endif  // _HOME_SEBASTIAN_CLIONPROJECTS_TPGRUPAL_COMMONQUEUE_H_