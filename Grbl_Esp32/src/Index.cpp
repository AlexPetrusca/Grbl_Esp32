#include "Grbl.h"

// Probe pin initialization routine.
void index_init() {
    static bool show_init_msg = true;  // used to show message only once.

    if (INDEX_PIN != UNDEFINED_PIN) {
        pinMode(INDEX_PIN, INPUT);

        if (show_init_msg) {
            grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "Index on pin %s", pinName(PROBE_PIN).c_str());
            show_init_msg = false;
        }
    }
}

// Returns the index
bool index_get_state() {
    return digitalRead(INDEX_PIN) == HIGH;
}

// Monitors index pin state in a tight loop. Waits for a falling edge before falling through.
void index_state_monitor() {
    boolean last_state = index_get_state();
    while (true) {
        boolean curr_state = index_get_state();
        if (last_state && !curr_state) { // FALLING if: last == HIGH, curr == LOW
            return;
        }
        last_state = curr_state;
    }
}
