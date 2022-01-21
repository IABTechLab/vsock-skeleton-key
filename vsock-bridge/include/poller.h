#pragma once

#include <eventdef.h>

namespace vsockio
{
	struct Poller
	{
		virtual int add(int fd, void* handler, uint32_t events) = 0;

		virtual int update(int fd, void* handler, uint32_t events) = 0;

		virtual void remove(int fd) = 0;

		virtual int poll(VsbEvent* outEvents, int timeout) = 0;

		int maxEventsPerPoll() const { return _maxEvents; }

		int _maxEvents;
	};
}