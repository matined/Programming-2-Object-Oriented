#ifndef FLOAT_NUMBER_HEADER
#define FLOAT_NUMBER_HEADER

static constexpr int MAX_DECIMAL_VALUE = 1000;

class FloatNumber
{
	int integerValue;
	int decimalValue;

public:
	/* ADD DECLARATION OF FLOATNUMBER'S CONSTRUCTORS HERE */


	/* ADD DECLARATION OF FLOATNUMBER'S METHODS HERE */


	/* YOU DON'T HAVE TO DECLARE YOURSELF THIS METHOD - JUST IMPLEMENT IT IN FLOATNUMBER.CPP FILE */
	bool Equals(const FloatNumber& other) const;

	/* YOU DON'T HAVE TO DECLARE YOURSELF THIS OPERATOR - JUST IMPLEMENT IT IN FLOATNUMBER.CPP FILE */
	friend FloatNumber operator + (const FloatNumber& floatA, const FloatNumber& floatB);
};

#endif /* FLOAT_NUMBER_HEADER */
