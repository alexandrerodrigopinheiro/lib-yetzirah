#include "emitter/emitter.h"

std::ostream& ygl::emitter::operator<<(std::ostream& stream, const ygl::emitter::sprain& sprain)
{
	switch (sprain)
	{
		case ygl::emitter::sprain::SPRAIN_NORMAL:    { stream << "SPRAIN { NORMAL }";    break; }
		case ygl::emitter::sprain::SPRAIN_JET:       { stream << "SPRAIN { JET }";       break; }
		case ygl::emitter::sprain::SPRAIN_EXPLOSION: { stream << "SPRAIN { EXPLOSION }"; break; }
		case ygl::emitter::sprain::SPRAIN_SQUARE:    { stream << "SPRAIN { NORMAL }";    break; }
		case ygl::emitter::sprain::SPRAIN_STAR:      { stream << "SPRAIN { STAR }";      break; }
		case ygl::emitter::sprain::SPRAIN_CIRCLE:    { stream << "SPRAIN { CIRCLE }";    break; }
		case ygl::emitter::sprain::SPRAIN_SPIRAL:    { stream << "SPRAIN { SPIRAL }";    break; }
		case ygl::emitter::sprain::SPRAIN_TAN_COS:   { stream << "SPRAIN { TAN_COS }";   break; }
		case ygl::emitter::sprain::SPRAIN_TAN_SIN:   { stream << "SPRAIN { TAN_SIN }";   break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_1:  { stream << "SPRAIN { RANDOM_1 }";  break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_2:  { stream << "SPRAIN { RANDOM_2 }";  break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_3:  { stream << "SPRAIN { RANDOM_3 }";  break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_4:  { stream << "SPRAIN { RANDOM_4 }";  break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_5:  { stream << "SPRAIN { RANDOM_5 }";  break; }
		case ygl::emitter::sprain::SPRAIN_RANDOM_6:  { stream << "SPRAIN { RANDOM_6 }";  break; }
	}

	return stream;
}

std::istream& ygl::emitter::operator>>(std::istream& stream, ygl::emitter::sprain& sprain)
{
	std::string garbage;
	std::string value;

	stream >> garbage;
	stream >> garbage;
	stream >> value;
	stream >> garbage;

	     if (value == "NORMAL")    { sprain = ygl::emitter::sprain::SPRAIN_NORMAL;    }
	else if (value == "JET")       { sprain = ygl::emitter::sprain::SPRAIN_JET;       }
	else if (value == "EXPLOSION") { sprain = ygl::emitter::sprain::SPRAIN_EXPLOSION; }
	else if (value == "SQUARE")    { sprain = ygl::emitter::sprain::SPRAIN_SQUARE;    }
	else if (value == "STAR")      { sprain = ygl::emitter::sprain::SPRAIN_STAR;      }
	else if (value == "CIRCLE")    { sprain = ygl::emitter::sprain::SPRAIN_CIRCLE;    }
	else if (value == "SPIRAL")    { sprain = ygl::emitter::sprain::SPRAIN_SPIRAL;    }
	else if (value == "TAN_COS")   { sprain = ygl::emitter::sprain::SPRAIN_TAN_COS;   }
	else if (value == "TAN_SIN")   { sprain = ygl::emitter::sprain::SPRAIN_TAN_SIN;   }
	else if (value == "RANDOM_1")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_1;  }
	else if (value == "RANDOM_2")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_2;  }
	else if (value == "RANDOM_3")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_3;  }
	else if (value == "RANDOM_4")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_4;  }
	else if (value == "RANDOM_5")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_5;  }
	else if (value == "RANDOM_6")  { sprain = ygl::emitter::sprain::SPRAIN_RANDOM_6;  }

	return stream;
}

ygl::emitter::sprain ygl::emitter::to_sprain(const std::string& sprain)
{
	ygl::emitter::sprain out;

	     if (sprain == "NORMAL")    { out = ygl::emitter::sprain::SPRAIN_NORMAL; }
	else if (sprain == "JET")       { out = ygl::emitter::sprain::SPRAIN_JET; }
	else if (sprain == "EXPLOSION") { out = ygl::emitter::sprain::SPRAIN_EXPLOSION; }
	else if (sprain == "SQUARE")    { out = ygl::emitter::sprain::SPRAIN_SQUARE; }
	else if (sprain == "STAR")      { out = ygl::emitter::sprain::SPRAIN_STAR; }
	else if (sprain == "CIRCLE")    { out = ygl::emitter::sprain::SPRAIN_CIRCLE; }
	else if (sprain == "SPIRAL")    { out = ygl::emitter::sprain::SPRAIN_SPIRAL; }
	else if (sprain == "TAN_COS")   { out = ygl::emitter::sprain::SPRAIN_TAN_COS; }
	else if (sprain == "TAN_SIN")   { out = ygl::emitter::sprain::SPRAIN_TAN_SIN; }
	else if (sprain == "RANDOM_1")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_1; }
	else if (sprain == "RANDOM_2")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_2; }
	else if (sprain == "RANDOM_3")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_3; }
	else if (sprain == "RANDOM_4")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_4; }
	else if (sprain == "RANDOM_5")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_5; }
	else if (sprain == "RANDOM_6")  { out = ygl::emitter::sprain::SPRAIN_RANDOM_6; }

	return out;
}
