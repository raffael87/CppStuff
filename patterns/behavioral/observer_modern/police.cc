#include <iostream>

#include "police.h"
#include "publisher.h"

template <typename Subscriber>
Police<Subscriber>::Police(Publisher<Subscriber>* publisher) :
	publisher_(publisher)
{
	std::cout << " Police::Police() subscribe to publisher" << std::endl;
	std::function<void()> func = std::bind( &Police::Alarm, this);
	publisher_->Subscribe(func);
}

template <typename Subscriber>
Police<Subscriber>::~Police()
{
	std::cout << " Police::~Police() unsubscribe to publisher" << std::endl;
	//publisher_->Unsubscribe(this);
}

template <typename Subscriber>
void Police<Subscriber>::Alarm()
{
	//if(publisher == publisher_)
	//{
		std::cout << " Police::Alarm() event received from publisher" << std::endl;
	//}
}

template class Police<std::function<void()>>;
