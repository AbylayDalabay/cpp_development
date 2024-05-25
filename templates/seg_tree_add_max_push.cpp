template<class Info, class Tag>
class LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    void pull(int id) {
        info[id] = info[id << 1] + info[id << 1 | 1];
    }
    void apply(int id, const Tag &v) {
        info[id] += v;
        tag[id] += v;
    }
    void push(int id) {
        apply(id << 1, tag[id]);
        apply(id << 1 | 1, tag[id]);
        tag[id] = Tag();
    }
    void modify(int id, int l, int r, int p, const Info &v) {
        if (r == l) {
            info[id] = v;
            return;
        }
        int m = (l + r) >> 1;
        push(id);
        if (p <= m) modify(id << 1, l, m, p, v);
        else modify(id << 1 | 1, m + 1, r, p, v);
        pull(id);
    }
    Info rangeQuery(int id, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Info();
        if (ql <= l && r <= qr) return info[id];
        int m = (l + r) >> 1;
        push(id);
        return rangeQuery(id << 1, l, m, ql, qr) + rangeQuery(id << 1 | 1, m + 1, r, ql, qr);
    }
    void rangeApply(int id, int l, int r, int ql, int qr, const Tag &v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(id, v);
            return;
        }
        int m = (l + r) >> 1;
        push(id);
        rangeApply(id << 1, l, m, ql, qr, v);
        rangeApply(id << 1 | 1, m + 1, r, ql, qr, v);
        pull(id);
    }
public:
    LazySegmentTree(int _n) : n(_n), info(4 * n), tag(4 * n) {}
template <typename T>
    LazySegmentTree(vector<T> init) : LazySegmentTree((int)init.size()) {
        auto build = [&](auto _build, int id, int l, int r) -> void {
            if (r == l) {
                info[id] = init[l];
                return;
            }
            int m = (l + r) >> 1;
            _build(_build, id << 1, l, m);
            _build(_build, id << 1 | 1, m + 1, r);
            pull(id);
        };
        build(build, 1, 0, n - 1);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n - 1, p, v);
    }
    void rangeApply(int ql, int qr, const Tag &v) {
        return rangeApply(1, 0, n - 1, ql, qr, v);
    }
    Info rangeQuery(int ql, int qr) {
        return rangeQuery(1, 0, n - 1, ql, qr);
    }
    // struct Info{ Info() {} };
    // struct Tag{ Tag() {} };
    // Info operator+(Info l, Info r){ rt l; }
    // Info& operator+=(Info &l, Tag r) { rt l; }
    // Tag& operator+=(Tag &l, Tag r) { rt l; }
};