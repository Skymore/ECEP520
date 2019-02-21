#ifndef _EVENT_H
#define _EVENT_H

#include <string>
#include <vector>
#include <json/json.h>

using std::string;
using std::vector;
using nlohmann::json; 

namespace elma {

    //! Events that can be emitted, watched, and responded to with event handlers.

    //! Events are constructed with a jsonable value, as in
    //! @code
    //!    Event(3.14);
    //!    Event("hello world");
    //!    Event({1,2,3});
    //! @endcode
    //! See https://github.com/nlohmann/json for details about how to define and manipulated json values.
    class Event {

        public:

        //! Cpnstruct a new event
        //! \param value A json object 
        Event(json value) : _value(value), _propagate(true) {}

        //! Get the data value associated with an event
        //! \return The value
        inline json value() const { return _value; }

        //! Determine whether the event will propagate to the next event handler
        //! \return True or false
        inline bool propagate() const { return _propagate; }

        //! Prevent the event from propagating to the next event handler. Typically
        //! called within an event handler to prevent an subsequent events that
        //! are watching the same event from firing. See the Manager methods emit() and watch().
        inline void stop_propagation() { _propagate = false; }

        //! Turn propagation back on
        inline void reset() { _propagate = true; }

        private:
        json _value;
        bool _propagate;

    };

}

#endif