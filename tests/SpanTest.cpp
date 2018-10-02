#include <cassert>
#include <vector>
#include "../Span.h"

using philwill::Span;

template <typename CharT>
int arrayTest() {
  CharT const array[] = {CharT('H'), CharT('e'), CharT('l'), CharT('l'),
                         CharT('o')};
  Span<CharT const*> test(array);
  assert(5 == test.size() && "size() must be 5");
  CharT const* iter = test.begin();
  assert(iter && "begin() must not be nullptr");
  assert(*iter++ == CharT('H') && "Content wrong");
  assert(*iter++ == CharT('e') && "Content wrong");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(*iter++ == CharT('o') && "Content wrong");
  assert(iter == test.end() && "end() in the wrong place");
  return 0;
}

template <typename CharT>
int pointerPairTest() {
  CharT const array[] = {CharT('H'), CharT('e'), CharT('l'), CharT('l'),
                         CharT('o')};
  Span<CharT const*> test(&array[0], &array[5]);
  assert(5 == test.size() && "size() must be 5");
  CharT const* iter = test.begin();
  assert(iter && "begin() must not be nullptr");
  assert(*iter++ == CharT('H') && "Content wrong");
  assert(*iter++ == CharT('e') && "Content wrong");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(*iter++ == CharT('o') && "Content wrong");
  assert(iter == test.end() && "end() in the wrong place");
  return 0;
}

template <typename CharT>
int vectorTest() {
  std::vector<CharT> vec = {CharT('H'), CharT('e'), CharT('l'), CharT('l'),
                            CharT('o')};
  Span<typename std::vector<CharT>::const_iterator> test(std::as_const(vec));
  assert(5 == test.size() && "size() must be 5");
  auto iter = test.begin();
  assert(iter != test.end() && "begin() must not be end()");
  assert(*iter++ == CharT('H') && "Content wrong");
  assert(iter != test.end() && "unexpected early end()");
  assert(*iter++ == CharT('e') && "Content wrong");
  assert(iter != test.end() && "unexpected early end()");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(iter != test.end() && "unexpected early end()");
  assert(*iter++ == CharT('l') && "Content wrong");
  assert(iter != test.end() && "unexpected early end()");
  assert(*iter++ == CharT('o') && "Content wrong");
  assert(iter == test.end() && "unexpected late end()");
  return 0;
}

template <typename CharT>
int equalityTest() {
  CharT const array[] = {CharT('H'), CharT('i'), CharT('!'), CharT('H'),
                         CharT('i')};
  Span<CharT const*> test1(&array[0], &array[2]);
  Span<CharT const*> test2(&array[0], &array[3]);
  Span<CharT const*> test3(&array[3], &array[5]);
  assert(test1 == test1 && "span should equal itself");
  assert(test2 == test2 && "span should equal itself");
  assert(test3 == test3 && "span should equal itself");

  assert(test1 == test3 && "span should equal span with same content");
  assert(test3 == test1 && "span should equal span with same content");
  assert(test1 != test2 && "span should not equal span with different content");
  assert(test2 != test1 && "span should not equal span with different content");
  return 0;
}

template <typename CharT>
int doTest() {
  return arrayTest<CharT>() + pointerPairTest<CharT>() + vectorTest<CharT>() + equalityTest<CharT>();
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}