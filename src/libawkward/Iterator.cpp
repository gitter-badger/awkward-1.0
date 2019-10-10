// BSD 3-Clause License; see https://github.com/jpivarski/awkward-1.0/blob/master/LICENSE

#include <sstream>

#include "awkward/Iterator.h"

namespace awkward {
  const bool Iterator::isdone() const {
    return where_ >= content_.get()->length();
  }

  const std::shared_ptr<Content> Iterator::next() {
    return content_.get()->getitem_at_unsafe(where_++);
  }

  const std::string Iterator::tostring_part(const std::string indent, const std::string pre, const std::string post) const {
    std::stringstream out;
    out << indent << pre << "<Iterator where=\"" << where_ << "\">\n";
    out << content_.get()->tostring_part(indent + std::string("    "), "", "\n");
    out << indent << "</Iterator>" << post;
    return out.str();
  }

  const std::string Iterator::tostring() const {
    return tostring_part("", "", "");
  }
}