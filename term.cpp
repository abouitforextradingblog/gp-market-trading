/***************************************************************************
 * (c) 2008-2011 Aleksandar Topuzović                                      *
 * <aleksandar.topuzovic@fer.hr>, <aleksandar.topuzovic@gmail.com>         *
 ***************************************************************************/
#include "term.hpp"

using namespace trading;

TermOp::TermOp(Beagle::string inName) :
  TerminationOp(inName)
{	}

bool TermOp::terminate(const Beagle::Deme& inDeme, Beagle::Context& ioContext)
{
	// TODO - do complex criteria termination
	std::cout << "TODO - do complex criteria termination" << std::endl;
	return true;
}
