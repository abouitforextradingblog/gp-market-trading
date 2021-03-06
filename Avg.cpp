/***************************************************************************
 * (c) 2008-2011 Aleksandar Topuzović                                      *
 * <aleksandar.topuzovic@fer.hr>, <aleksandar.topuzovic@gmail.com>         *
 ***************************************************************************/
#include "beagle/GP.hpp"
#include "Avg.hpp"
#include "util.hpp"

#include <sstream>
#include <cmath>
#include <fstream>

using namespace Beagle;

// Ime AVG
Avg::Avg() :
  Beagle::GP::Primitive(1, "AVG")
{ }

#ifdef BEAGLE_HAVE_RTTI

// Argumenti tipa Double
const std::type_info* Avg::getArgType(unsigned int inN, Beagle::GP::Context& ioContext) const
{
  Beagle_AssertM(inN < 1);
  return &typeid(UInt);
}

// Povratna vrjednost double
const std::type_info* Avg::getReturnType(Beagle::GP::Context& ioContext) const
{
  return &typeid(Double);
}

#endif // BEAGLE_HAVE_RTTI

// Vraca srednju vrjednost dionice kroz period
void Avg::execute(GP::Datum& outDatum, GP::Context& ioContext)
{
	Double& lResult = castObjectT<Double&>(outDatum);
	UInt lArg;
	get1stArgument(lArg, ioContext); 
	trading::Context& aContext = castObjectT<trading::Context&>(ioContext);

	sqlite3 *database;		// Baza podataka  
	database = aContext.database;

	std::ostringstream interval;
	interval << lArg;

	string sql = "SELECT AVG(ZADNJA) FROM ZSE WHERE DIONICA=UPPER('";
	sql       += aContext.dionica;				// Dionica
	sql       += "') AND DATUM BETWEEN DATE('";
	sql       += aContext.datum;
	sql       += "','-"; 
	sql       += interval.str();				// Vremenski interval
	sql       += " day') AND DATE('";
	sql       += aContext.datum;				// Trenutni datum
	sql       += "');"; 

	//std::cout << sql << std::endl;

	sqlite3_stmt *preparedStatement;
	SQLITE_PREPARE_STATEMENT_TEST(preparedStatement, sql, database);
	SQLITE_STEP_TEST(preparedStatement);
	
	lResult = sqlite3_column_double(preparedStatement,0);
	sqlite3_finalize(preparedStatement);
	//std::cout << "AVG:" << lResult << std::endl;
}
