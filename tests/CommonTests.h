#include <utility>
#include "../Span.h"

namespace philwill {
namespace tests {
template <typename Visitable>
int correctVisitorTest(Visitable const& visitable) {
  using CharT = typename Visitable::char_type;
  struct RvalueVisitor {
    void operator()(philwill::Span<CharT const*> const& span) && {}
    void operator()(philwill::Span<CharT const*> const& span) const&& {
      assert(false && "Const rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const& {
      assert(false && "Const lvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) & {
      assert(false && "lvalue visitor unexpectedly invoked");
    }
  };
  struct ConstRvalueVisitor {
    void operator()(philwill::Span<CharT const*> const& span) && {
      assert(false && "rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const&& {}
    void operator()(philwill::Span<CharT const*> const& span) const& {
      assert(false && "Const lvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) & {
      assert(false && "lvalue visitor unexpectedly invoked");
    }
  };
  struct LvalueVisitor {
    void operator()(philwill::Span<CharT const*> const& span) && {
      assert(false && "rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const&& {
      assert(false && "Const rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const& {
      assert(false && "Const lvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) & {}
  };
  struct ConstLvalueVisitor {
    void operator()(philwill::Span<CharT const*> const& span) && {
      assert(false && "rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const&& {
      assert(false && "Const rvalue visitor unexpectedly invoked");
    }
    void operator()(philwill::Span<CharT const*> const& span) const& {}
    void operator()(philwill::Span<CharT const*> const& span) & {
      assert(false && "lvalue visitor unexpectedly invoked");
    }
  };
  LvalueVisitor lvalueVisitor;
  ConstLvalueVisitor const constLvalueVisitor;
  RvalueVisitor rvalueVisitor;
  ConstRvalueVisitor const constRvalueVisitor;
  visitable.accept(lvalueVisitor);
  visitable.accept(constLvalueVisitor);
  visitable.accept(std::move(rvalueVisitor));
  visitable.accept(std::move(constRvalueVisitor));
  return 0;
}
}  // namespace tests
}  // namespace philwill