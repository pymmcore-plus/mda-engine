#ifndef _event_data_manager_H
#define _event_data_manager_H
#ifdef _MSC_VER
// We use exception specifications to instruct SWIG to generate the correct
// exception specifications for Java. Turn off the warnings that VC++ issues by
// the mere use of exception specifications (which VC++ does not implement).
#pragma warning(disable : 4290)
#endif
#include "BaseEventNotifier.h"
#include "MDAEvent.h"
#include "EventMetaData.h"
#include <map>

class MDAEvent;
class EventMetaData;

class EventDataManager : public BaseEventNotifier{
    public:
        EventDataManager();
        bool notifyRegistered(MDAEvent& event);
        bool notifyStart(MDAEvent& event);
        bool notifyPauseToggled(MDAEvent& event, bool paused);
        bool notifyCanceled(MDAEvent& event);
        bool notifyFinished(MDAEvent& event);
        bool notifyFrameReady(MDAEvent& event, std::map<std::string, std::string> &metadata, void* image, 
                            unsigned imageWidth, unsigned imageHeight, unsigned bytesPerPixel, unsigned imageBitDepth);

        // Fetching data from acquisition
        EventState getState(int event_id);
        // EventMetaData& getEventMetaData(int event_id);
        void* getImage(int event_id);
        // to get the image, we need few things:
        unsigned getImageWidth() ;
        unsigned getImageHeight() ;
        unsigned getBytesPerPixel() ;
        unsigned getImageBitDepth() ;

        // double secondsTaken();
    private:
    int lastEventId_;
    std::map<int, EventMetaData&> eventsState_;
};

#endif // _event_data_manager_H