//
//  MachineDelegate.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-08.
//

#ifndef MachineDelegate_h
#define MachineDelegate_h

class Machine;
class Message;

class MachineDelegate {
public:
	virtual void machineSendsMessage(Machine * aMachine, Message * aMessage) = 0;
	virtual void machineSaysSomething(Machine * aMachine, const std::string &caption) = 0;
	virtual void machineExecuteEvent(Machine * aMachine, const Event &event) = 0;
};


#endif /* MachineDelegate_h */