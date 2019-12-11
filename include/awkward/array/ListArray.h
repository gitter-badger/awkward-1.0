// BSD 3-Clause License; see https://github.com/jpivarski/awkward-1.0/blob/master/LICENSE

#ifndef AWKWARD_LISTARRAY_H_
#define AWKWARD_LISTARRAY_H_

#include <memory>

#include "awkward/cpu-kernels/util.h"
#include "awkward/Index.h"
#include "awkward/Identity.h"
#include "awkward/Content.h"

namespace awkward {
  template <typename T>
  class ListArrayOf: public Content {
  public:
    ListArrayOf<T>(const std::shared_ptr<Identity> id, const std::shared_ptr<Type> type, const IndexOf<T> starts, const IndexOf<T> stops, const std::shared_ptr<Content> content)
        : Content(id, type)
        , starts_(starts)
        , stops_(stops)
        , content_(content) { }

    const IndexOf<T> starts() const { return starts_; }
    const IndexOf<T> stops() const { return stops_; }
    const std::shared_ptr<Content> content() const { return content_; }

    virtual const std::string classname() const;
    virtual void setid();
    virtual void setid(const std::shared_ptr<Identity> id);
    virtual const std::string tostring_part(const std::string indent, const std::string pre, const std::string post) const;
    virtual void tojson_part(ToJson& builder) const;
    virtual const std::shared_ptr<Type> innertype(bool bare) const;
    virtual void settype_part(const std::shared_ptr<Type> type);
    virtual bool accepts(const std::shared_ptr<Type> type);
    virtual int64_t length() const;
    virtual const std::shared_ptr<Content> shallow_copy() const;
    virtual void check_for_iteration() const;
    virtual const std::shared_ptr<Content> getitem_nothing() const;
    virtual const std::shared_ptr<Content> getitem_at(int64_t at) const;
    virtual const std::shared_ptr<Content> getitem_at_nowrap(int64_t at) const;
    virtual const std::shared_ptr<Content> getitem_range(int64_t start, int64_t stop) const;
    virtual const std::shared_ptr<Content> getitem_range_nowrap(int64_t start, int64_t stop) const;
    virtual const std::shared_ptr<Content> getitem_field(const std::string& key) const;
    virtual const std::shared_ptr<Content> getitem_fields(const std::vector<std::string>& keys) const;
    virtual const std::shared_ptr<Content> carry(const Index64& carry) const;
    virtual const std::pair<int64_t, int64_t> minmax_depth() const;
    virtual int64_t numfields() const;
    virtual int64_t fieldindex(const std::string& key) const;
    virtual const std::string key(int64_t fieldindex) const;
    virtual bool haskey(const std::string& key) const;
    virtual const std::vector<std::string> keyaliases(int64_t fieldindex) const;
    virtual const std::vector<std::string> keyaliases(const std::string& key) const;
    virtual const std::vector<std::string> keys() const;

  protected:
    virtual const std::shared_ptr<Content> getitem_next(const SliceAt& at, const Slice& tail, const Index64& advanced) const;
    virtual const std::shared_ptr<Content> getitem_next(const SliceRange& range, const Slice& tail, const Index64& advanced) const;
    virtual const std::shared_ptr<Content> getitem_next(const SliceArray64& array, const Slice& tail, const Index64& advanced) const;

  private:
    const IndexOf<T> starts_;
    const IndexOf<T> stops_;
    const std::shared_ptr<Content> content_;
  };

  typedef ListArrayOf<int32_t>  ListArray32;
  typedef ListArrayOf<uint32_t> ListArrayU32;
  typedef ListArrayOf<int64_t>  ListArray64;
}

#endif // AWKWARD_LISTARRAY_H_