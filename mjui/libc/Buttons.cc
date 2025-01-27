#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include "BaseWidget.cc"
#include "fltk_utils.cc"

class Button : public Fl_Button {
    private:
        const char* id;
    public: 
        Button(int x, int y, int w, int h, char* label): Fl_Button(x, y, w, h, label) {
            id="buttonidherd";
        };


    int handle(int event) override {
        switch (event) {
            case FL_PUSH:
                enqueueEvent(id, event);
                return Fl_Button::handle(event); // Event handled

            case FL_ENTER: // Mouse enters button area
                // Optional: Change appearance or state for hover effect
                return Fl_Button::handle(event); // Call base class for default behavior

            case FL_LEAVE: // Mouse leaves button area
                // Optional: Revert appearance or state
                return Fl_Button::handle(event); // Call base class for default behavior

            default:
                return Fl_Button::handle(event); // Pass all other events to base class
        }
    }

};