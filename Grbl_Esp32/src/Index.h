#pragma once

// Values that define the indexing state machine.
enum class Index : uint8_t {
    Off    = 0,  // Indexing disabled or not in use. (Must be zero.)
    Active = 1,  // Actively watching the index input pin.
};

void index_init();

bool index_get_state();

void index_state_monitor();