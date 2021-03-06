/***************************************************************************
 * (c) 2008-2011 Aleksandar Topuzović                                      *
 * <aleksandar.topuzovic@fer.hr>, <aleksandar.topuzovic@gmail.com>         *
 ***************************************************************************/
#ifndef MACD_hpp
#define MACD_hpp

#include "beagle/GP.hpp"
#include "sqlite3.h"
#include "Context.hpp"
#include <string>

#ifdef BEAGLE_HAVE_RTTI
#include <typeinfo>
#endif // BEAGLE_HAVE_RTTI

class MACD : public Beagle::GP::Primitive {

public:
	typedef Beagle::AllocatorT<MACD,Beagle::GP::Primitive::Alloc> Alloc;
	typedef Beagle::PointerT<MACD,Beagle::GP::Primitive::Handle> Handle;
	typedef Beagle::ContainerT<MACD,Beagle::GP::Primitive::Bag> Bag;

	explicit MACD();
	virtual ~MACD() { }

#ifdef BEAGLE_HAVE_RTTI
	virtual const std::type_info* getReturnType(Beagle::GP::Context& ioContext) const;
#endif // BEAGLE_HAVE_RTTI

	virtual void                  execute(Beagle::GP::Datum& outDatum, Beagle::GP::Context& ioContext);
};

#endif // MACD_hpp
