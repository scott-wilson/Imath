//
// SPDX-License-Identifier: BSD-3-Clause
// Copyright Contributors to the OpenEXR Project.
//

#ifndef INCLUDED_IMATHSHEAR_H
#define INCLUDED_IMATHSHEAR_H

//----------------------------------------------------
//
//	Shear6 class template.
//
//----------------------------------------------------

#include "ImathLimits.h"
#include "ImathMath.h"
#include "ImathNamespace.h"
#include "ImathVec.h"
#include <iostream>

IMATH_INTERNAL_NAMESPACE_HEADER_ENTER

template <class T> class Shear6
{
  public:
    //-------------------
    // Access to elements
    //-------------------

    T xy, xz, yz, yx, zx, zy;

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 T& operator[] (int i);
    IMATH_HOSTDEVICE constexpr const T& operator[] (int i) const;

    //-------------
    // Constructors
    //-------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6();                  // (0 0 0 0 0 0)
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (T XY, T XZ, T YZ); // (XY XZ YZ 0 0 0)
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (const Vec3<T>& v); // (v.x v.y v.z 0 0 0)
    template <class S>
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (const Vec3<S>& v); // (v.x v.y v.z 0 0 0)
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (T XY,              // (XY XZ YZ YX ZX ZY)
                                               T XZ,
                                               T YZ,
                                               T YX,
                                               T ZX,
                                               T ZY);

    //---------------------------------
    // Copy constructors and assignment
    //---------------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (const Shear6& h);
    template <class S> IMATH_HOSTDEVICE IMATH_CONSTEXPR14 Shear6 (const Shear6<S>& h);

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator= (const Shear6& h);
    template <class S>
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator= (const Vec3<S>& v);

    //------------
    // Destructor
    //------------

    ~Shear6() = default;

    //----------------------
    // Compatibility with Sb
    //----------------------

    template <class S> IMATH_HOSTDEVICE void setValue (S XY, S XZ, S YZ, S YX, S ZX, S ZY);

    template <class S> IMATH_HOSTDEVICE void setValue (const Shear6<S>& h);

    template <class S>
    IMATH_HOSTDEVICE void getValue (S& XY, S& XZ, S& YZ, S& YX, S& ZX, S& ZY) const;

    template <class S> IMATH_HOSTDEVICE void getValue (Shear6<S>& h) const;

    IMATH_HOSTDEVICE T* getValue();
    IMATH_HOSTDEVICE const T* getValue() const;

    //---------
    // Equality
    //---------

    template <class S> IMATH_HOSTDEVICE constexpr bool operator== (const Shear6<S>& h) const;

    template <class S> IMATH_HOSTDEVICE constexpr bool operator!= (const Shear6<S>& h) const;

    //-----------------------------------------------------------------------
    // Compare two shears and test if they are "approximately equal":
    //
    // equalWithAbsError (h, e)
    //
    //	    Returns true if the coefficients of this and h are the same with
    //	    an absolute error of no more than e, i.e., for all i
    //
    //      abs (this[i] - h[i]) <= e
    //
    // equalWithRelError (h, e)
    //
    //	    Returns true if the coefficients of this and h are the same with
    //	    a relative error of no more than e, i.e., for all i
    //
    //      abs (this[i] - h[i]) <= e * abs (this[i])
    //-----------------------------------------------------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 bool equalWithAbsError (const Shear6<T>& h, T e) const;
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 bool equalWithRelError (const Shear6<T>& h, T e) const;

    //------------------------
    // Component-wise addition
    //------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator+= (const Shear6& h);
    IMATH_HOSTDEVICE constexpr Shear6 operator+ (const Shear6& h) const;

    //---------------------------
    // Component-wise subtraction
    //---------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator-= (const Shear6& h);
    IMATH_HOSTDEVICE constexpr Shear6 operator- (const Shear6& h) const;

    //------------------------------------
    // Component-wise multiplication by -1
    //------------------------------------

    IMATH_HOSTDEVICE constexpr Shear6 operator-() const;
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& negate();

    //------------------------------
    // Component-wise multiplication
    //------------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator*= (const Shear6& h);
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator*= (T a);
    IMATH_HOSTDEVICE constexpr Shear6 operator* (const Shear6& h) const;
    IMATH_HOSTDEVICE constexpr Shear6 operator* (T a) const;

    //------------------------
    // Component-wise division
    //------------------------

    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator/= (const Shear6& h);
    IMATH_HOSTDEVICE IMATH_CONSTEXPR14 const Shear6& operator/= (T a);
    IMATH_HOSTDEVICE constexpr Shear6 operator/ (const Shear6& h) const;
    IMATH_HOSTDEVICE constexpr Shear6 operator/ (T a) const;

    //----------------------------------------------------------
    // Number of dimensions, i.e. number of elements in a Shear6
    //----------------------------------------------------------

    IMATH_HOSTDEVICE constexpr static unsigned int dimensions() { return 6; }

    //-------------------------------------------------
    // Limitations of type T (see also class limits<T>)
    //-------------------------------------------------

    IMATH_HOSTDEVICE constexpr static T baseTypeMin() { return limits<T>::min(); }
    IMATH_HOSTDEVICE constexpr static T baseTypeMax() { return limits<T>::max(); }
    IMATH_HOSTDEVICE constexpr static T baseTypeSmallest() { return limits<T>::smallest(); }
    IMATH_HOSTDEVICE constexpr static T baseTypeEpsilon() { return limits<T>::epsilon(); }

    //--------------------------------------------------------------
    // Base type -- in templates, which accept a parameter, V, which
    // could be either a Vec2<T> or a Shear6<T>, you can refer to T as
    // V::BaseType
    //--------------------------------------------------------------

    typedef T BaseType;
};

//--------------
// Stream output
//--------------

template <class T> std::ostream& operator<< (std::ostream& s, const Shear6<T>& h);

//----------------------------------------------------
// Reverse multiplication: scalar * Shear6<T>
//----------------------------------------------------

template <class S, class T>
IMATH_HOSTDEVICE constexpr Shear6<T> operator* (S a, const Shear6<T>& h);

//-------------------------
// Typedefs for convenience
//-------------------------

typedef Vec3<float> Shear3f;
typedef Vec3<double> Shear3d;
typedef Shear6<float> Shear6f;
typedef Shear6<double> Shear6d;

//-----------------------
// Implementation of Shear6
//-----------------------

template <class T>
IMATH_CONSTEXPR14 inline T&
Shear6<T>::operator[] (int i)
{
    return (&xy)[i]; // NOSONAR - suppress SonarCloud bug report.
}

template <class T>
constexpr inline const T&
Shear6<T>::operator[] (int i) const
{
    return (&xy)[i]; // NOSONAR - suppress SonarCloud bug report.
}

template <class T> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6()
{
    xy = xz = yz = yx = zx = zy = 0;
}

template <class T> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (T XY, T XZ, T YZ)
{
    xy = XY;
    xz = XZ;
    yz = YZ;
    yx = 0;
    zx = 0;
    zy = 0;
}

template <class T> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (const Vec3<T>& v)
{
    xy = v.x;
    xz = v.y;
    yz = v.z;
    yx = 0;
    zx = 0;
    zy = 0;
}

template <class T> template <class S> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (const Vec3<S>& v)
{
    xy = T (v.x);
    xz = T (v.y);
    yz = T (v.z);
    yx = 0;
    zx = 0;
    zy = 0;
}

template <class T> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (T XY, T XZ, T YZ, T YX, T ZX, T ZY)
{
    xy = XY;
    xz = XZ;
    yz = YZ;
    yx = YX;
    zx = ZX;
    zy = ZY;
}

template <class T> IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (const Shear6& h)
{
    xy = h.xy;
    xz = h.xz;
    yz = h.yz;
    yx = h.yx;
    zx = h.zx;
    zy = h.zy;
}

template <class T>
template <class S>
IMATH_CONSTEXPR14 inline Shear6<T>::Shear6 (const Shear6<S>& h)
{
    xy = T (h.xy);
    xz = T (h.xz);
    yz = T (h.yz);
    yx = T (h.yx);
    zx = T (h.zx);
    zy = T (h.zy);
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator= (const Shear6& h)
{
    xy = h.xy;
    xz = h.xz;
    yz = h.yz;
    yx = h.yx;
    zx = h.zx;
    zy = h.zy;
    return *this;
}

template <class T>
template <class S>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator= (const Vec3<S>& v)
{
    xy = T (v.x);
    xz = T (v.y);
    yz = T (v.z);
    yx = 0;
    zx = 0;
    zy = 0;
    return *this;
}

template <class T>
template <class S>
inline void
Shear6<T>::setValue (S XY, S XZ, S YZ, S YX, S ZX, S ZY)
{
    xy = T (XY);
    xz = T (XZ);
    yz = T (YZ);
    yx = T (YX);
    zx = T (ZX);
    zy = T (ZY);
}

template <class T>
template <class S>
inline void
Shear6<T>::setValue (const Shear6<S>& h)
{
    xy = T (h.xy);
    xz = T (h.xz);
    yz = T (h.yz);
    yx = T (h.yx);
    zx = T (h.zx);
    zy = T (h.zy);
}

template <class T>
template <class S>
inline void
Shear6<T>::getValue (S& XY, S& XZ, S& YZ, S& YX, S& ZX, S& ZY) const
{
    XY = S (xy);
    XZ = S (xz);
    YZ = S (yz);
    YX = S (yx);
    ZX = S (zx);
    ZY = S (zy);
}

template <class T>
template <class S>
inline void
Shear6<T>::getValue (Shear6<S>& h) const
{
    h.xy = S (xy);
    h.xz = S (xz);
    h.yz = S (yz);
    h.yx = S (yx);
    h.zx = S (zx);
    h.zy = S (zy);
}

template <class T>
inline T*
Shear6<T>::getValue()
{
    return (T*) &xy;
}

template <class T>
inline const T*
Shear6<T>::getValue() const
{
    return (const T*) &xy;
}

template <class T>
template <class S>
constexpr inline bool
Shear6<T>::operator== (const Shear6<S>& h) const
{
    return xy == h.xy && xz == h.xz && yz == h.yz && yx == h.yx && zx == h.zx && zy == h.zy;
}

template <class T>
template <class S>
constexpr inline bool
Shear6<T>::operator!= (const Shear6<S>& h) const
{
    return xy != h.xy || xz != h.xz || yz != h.yz || yx != h.yx || zx != h.zx || zy != h.zy;
}

template <class T>
IMATH_CONSTEXPR14 inline bool
Shear6<T>::equalWithAbsError (const Shear6<T>& h, T e) const
{
    for (int i = 0; i < 6; i++)
        if (!IMATH_INTERNAL_NAMESPACE::equalWithAbsError ((*this)[i], h[i], e))
            return false;

    return true;
}

template <class T>
IMATH_CONSTEXPR14 inline bool
Shear6<T>::equalWithRelError (const Shear6<T>& h, T e) const
{
    for (int i = 0; i < 6; i++)
        if (!IMATH_INTERNAL_NAMESPACE::equalWithRelError ((*this)[i], h[i], e))
            return false;

    return true;
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator+= (const Shear6& h)
{
    xy += h.xy;
    xz += h.xz;
    yz += h.yz;
    yx += h.yx;
    zx += h.zx;
    zy += h.zy;
    return *this;
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator+ (const Shear6& h) const
{
    return Shear6 (xy + h.xy, xz + h.xz, yz + h.yz, yx + h.yx, zx + h.zx, zy + h.zy);
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator-= (const Shear6& h)
{
    xy -= h.xy;
    xz -= h.xz;
    yz -= h.yz;
    yx -= h.yx;
    zx -= h.zx;
    zy -= h.zy;
    return *this;
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator- (const Shear6& h) const
{
    return Shear6 (xy - h.xy, xz - h.xz, yz - h.yz, yx - h.yx, zx - h.zx, zy - h.zy);
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator-() const
{
    return Shear6 (-xy, -xz, -yz, -yx, -zx, -zy);
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::negate()
{
    xy = -xy;
    xz = -xz;
    yz = -yz;
    yx = -yx;
    zx = -zx;
    zy = -zy;
    return *this;
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator*= (const Shear6& h)
{
    xy *= h.xy;
    xz *= h.xz;
    yz *= h.yz;
    yx *= h.yx;
    zx *= h.zx;
    zy *= h.zy;
    return *this;
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator*= (T a)
{
    xy *= a;
    xz *= a;
    yz *= a;
    yx *= a;
    zx *= a;
    zy *= a;
    return *this;
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator* (const Shear6& h) const
{
    return Shear6 (xy * h.xy, xz * h.xz, yz * h.yz, yx * h.yx, zx * h.zx, zy * h.zy);
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator* (T a) const
{
    return Shear6 (xy * a, xz * a, yz * a, yx * a, zx * a, zy * a);
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator/= (const Shear6& h)
{
    xy /= h.xy;
    xz /= h.xz;
    yz /= h.yz;
    yx /= h.yx;
    zx /= h.zx;
    zy /= h.zy;
    return *this;
}

template <class T>
IMATH_CONSTEXPR14 inline const Shear6<T>&
Shear6<T>::operator/= (T a)
{
    xy /= a;
    xz /= a;
    yz /= a;
    yx /= a;
    zx /= a;
    zy /= a;
    return *this;
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator/ (const Shear6& h) const
{
    return Shear6 (xy / h.xy, xz / h.xz, yz / h.yz, yx / h.yx, zx / h.zx, zy / h.zy);
}

template <class T>
constexpr inline Shear6<T>
Shear6<T>::operator/ (T a) const
{
    return Shear6 (xy / a, xz / a, yz / a, yx / a, zx / a, zy / a);
}

//-----------------------------
// Stream output implementation
//-----------------------------

template <class T>
std::ostream&
operator<< (std::ostream& s, const Shear6<T>& h)
{
    return s << '(' << h.xy << ' ' << h.xz << ' ' << h.yz << h.yx << ' ' << h.zx << ' ' << h.zy
             << ')';
}

//-----------------------------------------
// Implementation of reverse multiplication
//-----------------------------------------

template <class S, class T>
constexpr inline Shear6<T>
operator* (S a, const Shear6<T>& h)
{
    return Shear6<T> (a * h.xy, a * h.xz, a * h.yz, a * h.yx, a * h.zx, a * h.zy);
}

IMATH_INTERNAL_NAMESPACE_HEADER_EXIT

#endif // INCLUDED_IMATHSHEAR_H
