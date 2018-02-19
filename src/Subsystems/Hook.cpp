#include "Hook.h"

Hook::Hook() {

}

void Hook::InitDefaultCommand() {

}

void Hook::Periodic() {

}

void Hook::ExtendHook() {
	HOOK_SOLENOID->Set(false); //needs to be tested
}
