#include <iostream>
#include <boost/shared_ptr.hpp>

static int ref = 0;

class Card
{
public:
  Card(int val) : val_(val)
  {
    ref++;
    std::cout << __FUNCTION__ << " " << ref << " " << (void*)this << " - val=" << val_ << std::endl;
  }

  ~Card()
  {
    ref--;
    std::cout << __FUNCTION__ << " " << ref << " " << (void*)this << " - val=" << val_ << std::endl;
  }

  int val_;
};

boost::shared_ptr<Card> create_card(boost::shared_ptr<Card> card, int val)
{
  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;
  card->val_ += val;
  return card;

}

int main()
{
  boost::shared_ptr<Card> card(new Card(2));
  boost::shared_ptr<Card> card2;

  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;
  create_card(card, 10);
  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;
  create_card(card, 10);
  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;
  create_card(card, 10);
  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;

  card2 = create_card(card, 10);

  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;
  std::cout << "card.val=" << card->val_ << std::endl;

  card.reset();
  std::cout << __LINE__ << ":" << "card.get()=" << card.get() << "," << card.use_count() << std::endl;


  return 0;
}

