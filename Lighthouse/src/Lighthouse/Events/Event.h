#pragma once

#include "../Core.h"


#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/format.h"
#include <spdlog/fmt/bundled/core.h>

namespace Lighthouse {
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLoseFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplicaiton = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategory() const override { return category; }

	class LIGHTHOUSE_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategory() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool isInCategory(EventCategory e) {
			return GetCategory() & e;
		}
	protected:
		bool isHandled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			: m_Event(e) {}

		template <typename T>
		bool Dispatch(EventFn<T> fn) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.isHandled = fn(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};


	/*
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
	*/

}
/*
template<>
struct fmt::formatter<Lighthouse::Event> : fmt::formatter<std::string> {
	template<typename FormatContext>
	auto format(const Lighthouse::Event& event, FormatContext& ctx) const -> decltype(ctx.out()) {
		return fmt::formatter<std::string>::format(event.ToString(), ctx);
	}
};
*/

template<typename T>
struct fmt::formatter<
	T, std::enable_if_t<std::is_base_of<Lighthouse::Event, T>::value, char>>
	: fmt::formatter<std::string> {
	auto format(const T& event, fmt::format_context& ctx) {
		return fmt::format_to(ctx.out(), event.ToString());
	}
};
