#pragma once

#include "Event.h"

namespace Lighthouse {
	class LIGHTHOUSE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int w, unsigned int h)
			: m_W(w), m_H(h) {}

		inline unsigned int getW() const { return m_W; }
		inline unsigned int getH() const { return m_H; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_W << ", " << m_H;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplicaiton)

	private:
		unsigned int m_W, m_H;
	};

	class LIGHTHOUSE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)		
		EVENT_CLASS_CATEGORY(EventCategoryApplicaiton)
	};

	class LIGHTHOUSE_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplicaiton)
	};

	class LIGHTHOUSE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplicaiton)
	};

	class LIGHTHOUSE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplicaiton)
	};
}

// Ensuring fmt can format derived class objects as well
/*
template<>
struct fmt::formatter<Lighthouse::WindowResizeEvent> : fmt::formatter<Lighthouse::Event> {};
*/

/*
template<>
struct fmt::formatter<Lighthouse::WindowResizeEvent> : fmt::formatter<std::string>
{

	auto format(Lighthouse::WindowResizeEvent e, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), e.ToString());
	}
};
*/