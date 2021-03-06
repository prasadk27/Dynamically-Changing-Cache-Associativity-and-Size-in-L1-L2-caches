// -*- C++ -*-
//
// Wrapper for quasi-standard "hash_map"/"hash_set" inclusion
//
// Jeff Brown
// $Id: hash-map.h,v 1.2.14.1.2.7 2009/03/02 21:24:04 jbrown Exp $
//

#ifndef HASH_MAP_H
#define HASH_MAP_H


// If we know where to find it, import "hash_map"/"hash_set"/"hash" into the
// current namespace.  This defines HAVE_HASHMAP as 0 or 1, to indicate
// whether or not they're usable.
//
// This also defines HASHMAP_IS_UNORDERED_MAP as 0 or 1, to indicate that the
// hash family containers are actually unordered_map/set/etc. from the newer
// C++ standards.  These have a mostly-compatible API, but significantly,
// offer the new semantic guarantee that element insertions and deletions do
// not invalidate iterators which point to other elements (similar to
// std::map).

#ifdef DISABLE_HASHMAP
    // Explicitly disable hashing-based containers
    #define HAVE_HASHMAP 0
    #define HASHMAP_IS_UNORDERED_MAP 0

#elif defined(__GNUC__) && (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)
    // Newer GCCs feature the TR1 unordered_map/set; and, somewhere <= 4.3.2,
    // GCC also starts complaining about uses of the old one
    #include <unordered_map>
    #include <unordered_set>
    using std::hash;
    #define hash_map std::unordered_map
    #define hash_multimap std::unordered_multimap
    #define hash_set std::unordered_set
    #define hash_multiset std::unordered_multiset
    #define HAVE_HASHMAP 1
    #define HASHMAP_IS_UNORDERED_MAP 1

#elif defined(__GNUC__)
    #include <ext/hash_map>
    #include <ext/hash_set>
    using __gnu_cxx::hash;
    using __gnu_cxx::hash_map;
    using __gnu_cxx::hash_multimap;
    using __gnu_cxx::hash_set;
    using __gnu_cxx::hash_multiset;
    #define HAVE_HASHMAP 1
    #define HASHMAP_IS_UNORDERED_MAP 0

#else
    #define HAVE_HASHMAP 0
    #define HASHMAP_IS_UNORDERED_MAP 0

#endif


#endif  /* HASH_MAP_H */
