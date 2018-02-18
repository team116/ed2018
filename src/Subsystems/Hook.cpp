#include "Hook.h"

Hook::Hook() {

}

void Hook::InitDefaultCommand() {

}

void Hook::Periodic() {

}

void Hook::ExtendHook() {
	HOOK_SOLENOID->Set(true); //needs to be tested
}
