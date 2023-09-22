#ifndef _BaseEventNotifier_H_
#define _BaseEventNotifier_H_

#ifdef _MSC_VER
// We use exception specifications to instruct SWIG to generate the correct
// exception specifications for Java. Turn off the warnings that VC++ issues by
// the mere use of exception specifications (which VC++ does not implement).
#pragma warning(disable : 4290)
#endif
#include <map>
#include "MDAPosition.h"
/*
There are 5 types of signals which needs to be handled by this class:
    Start event 
    PauseToggle event
    Canceled event
    Finished event
    frameReady event
*/
class BaseEventNotifier{
    public:
        virtual void notifyStart(MDAEvent& event) = 0;
        virtual void notifyPauseToggled(bool paused) = 0;
        virtual void notifyCanceled(MDAEvent& event) = 0;
        virtual void notifyFinished(MDAEvent& event) = 0;
        virtual void notifyFrameReady(MDAEvent& event, std::map<std::string, std::string> &metadata, void* image) = 0;
};


#endif // _BaseEventNotifier_H_