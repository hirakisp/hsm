# What's HSM

HSM is a state machine firmware for Embedded application.  
It's an abbreviation for hirakisp's state-machine.  

 * statemachine core library
 * code generator with data parser
 * Lightweight

The lastest source code is avalable here.

# Simple APIs

# hsm_init
Initialize structure of events and states.  
If defined initialize functions, It go to exec that functions.

+ Request *funcs, event_max, state_max
+ Response void

## hsm_run
Run state machine.

+ Request void
+ Response void

## hsm_set_ev
It go to set a event at hsm's queue.
A event has id and pointer data.

+ Request event_id, *event_data
+ Response void

# Code generator 

## Coding style

Doesnt use tab to indent, use 4-spaces instead.

## Supported import format

* T.B.D


# Debugging

Not yet supported. 
Comming soon.



# Whats new

 * Add generator
 * will support UML import format
