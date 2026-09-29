#ifndef TASKS_APP_H
#define TASKS_APP_H

#include <mutex>
#include <memory>
#include "../../domain/model/Person.h"
#include "../../domain/model/CategoryContainer.h"

using namespace std;

/**
 * Inspired on https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
 *
 * The App class works as a Singleton. It defines the `getInstance` method that serves as an alternative
 * to the constructor and lets client classes access the same instance of this class over and over.
 */
class App {
    /**
     * The Singleton's constructor/destructor should always be private to prevent
     * direct construction/destruction calls with the `new`/`delete` operator.
     */
private:
    static App *instance;
    static mutex mutex;
    shared_ptr<Person> person;
    shared_ptr<CategoryContainer> categoryContainer;

protected:
    App();

    ~App();

public:
    /**
     * Singleton classes should not be cloneable.
     */
    App(App &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const App &) = delete;

    /**
     * This is the static method that controls the access to the singleton instance.
     * On the first run, it creates a singleton object and places it into the static field.
     * On subsequent runs, it returns the existing object stored in the static field.
     */
    static App *getInstance();

    /**
     * Finally, the Singleton should define some business logic, which can be executed on its instance.
     */
    shared_ptr<Person> getPerson();

    shared_ptr<CategoryContainer> getCategoryContainer();
};

#endif //TASKS_APP_H