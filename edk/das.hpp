
#include <boost/operators.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/fold_left.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/preprocessor/list/for_each.hpp>


// each eliment in the list gets expanded to ", int <name><data>"
#define EdK_DAS_INTERAL_EXPAND_DECLARATION(r, data, elem) \
	 int  BOOST_PP_CAT(elem, data),

#define  EdK_DAS_DECLORATIONS(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLARATION, TAG, EdK_DAS_BASIS \
		) int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR, TAG) = 0

#define  EdK_DAS_DECLORATIONS_NO_DEFAULT(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLARATION, TAG, EdK_DAS_BASIS \
		) int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR, TAG)

#define  EdK_DAS_DECLORATIONS0 \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLARATION, , EdK_DAS_BASIS \
		) int EdK_DIM_LIST_TERMINATOR = 0

#define EdK_DAS_INTERAL_EXPAND_DECLARATION_SUM(r, data, elem) int elem + BOOST_PP_CAT(elem, data),

#define  EdK_DAS_DECLORATIONS_SUM(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLARATION_SUM, TAG, EdK_DAS_BASIS \
		) int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR_SUM, TAG) = 0


#define EdK_DAS_INTERAL_EXPAND_REFERANCES_SUM(r, data, elem) elem + BOOST_PP_CAT(elem, data),

#define  EdK_DAS_REFERANCES_SUM(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_REFERANCES_SUM, TAG, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR + BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR, TAG)

#define EdK_DAS_INTERAL_EXPAND_REFERANCES_DIF(r, data, elem) elem - BOOST_PP_CAT(elem, data),

#define  EdK_DAS_REFERANCES_DIF(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_REFERANCES_DIF, TAG, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR - BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR, TAG)



#define EdK_DAS_INTERAL_EXPAND_DECLARATION_DIF(r, data, elem) \
	int elem - BOOST_PP_CAT(elem, data),

#define  EdK_DAS_DECLORATIONS_DIFFERANCE(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLARATION_DIF, TAG, EdK_DAS_BASIS \
		)  int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR_DIF, TAG) = 0

#define EdK_DAS_INTERAL_EXPAND_DECLORATIONS_PRODUCT(r, data, elem) \
	int elem * data,
#define  EdK_DAS_DECLORATIONS_PRUDUCT(NUMBER) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLORATIONS_PRODUCT, NUMBER, EdK_DAS_BASIS \
		)  int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR_PRUDUCT_, NUMBER) = 0

#define EdK_DAS_INTERAL_EXPAND_DECLORATIONS_DIV(r, data, elem) \
	 int elem / data,
#define  EdK_DAS_DECLORATIONS_DIVISION(NUMBER) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DECLORATIONS_DIV, NUMBER, EdK_DAS_BASIS \
		) int BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR_DIV_, NUMBER) = 0


#define EdK_DAS_INTERAL_EXPAND_REF(r, data, elem) \
	 BOOST_PP_CAT(elem, data), 
#define  EdK_DAS_REFERANCES0 \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_REF, , EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR
#define  EdK_DAS_REFERANCES(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_REF, TAG, EdK_DAS_BASIS \
		) BOOST_PP_CAT(EdK_DIM_LIST_TERMINATOR, TAG)


#define EdK_DAS_INTERAL_EXPAND_SUM(r, data, elem) \
	 elem + BOOST_PP_CAT(elem, data), 
#define  EdK_DAS_SUM(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_SUM, TAG, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR_SUM



#define EdK_DAS_INTERAL_EXPAND_DIF(r, data, elem) \
	 elem - BOOST_PP_CAT(elem, data),
#define  EdK_DAS_DIFERANCE(TAG) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DIF, TAG, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR_DIF

#define EdK_DAS_INTERAL_EXPAND_PRODUCT(r, data, elem) \
	elem  * data,
#define  EdK_DAS_PRUDUCT(NUMBER) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_PRODUCT, NUMBER, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR_PRUDUCT

#define EdK_DAS_INTERAL_EXPAND_DIVIDE(r, data, elem) \
	elem  / data,
#define  EdK_DAS_DEVIDE(NUMBER) \
	BOOST_PP_LIST_FOR_EACH( \
		EdK_DAS_INTERAL_EXPAND_DEVIDE, NUMBER, EdK_DAS_BASIS \
		) EdK_DIM_LIST_TERMINATOR_DIV


#define EdK_DAS_INTERAL_CONST(r, data, elem) , data
#define EdK_DAS_CONST(CONST) \
		BOOST_PP_LIST_FOR_EACH( \
			EdK_DAS_INTERAL_CONST, CONST, EdK_DAS_BASIS \
		)



/// Tamplate for Dimentioned types
/**
 * Dimentioned types can be added and suptracted form types of the same dimentionality.
 *
 * They can be multiplied and devided by pure numeric values
 *
 * They can be multiplied and devided by other dimentioned types
 *      yealding a new dimentioned type
 *
 * They can be rased to integer powers yielding a new dimentioned type.
 *
 * Integer roots can be taken yeilding new dimentioned types.
 *
 * They can be compaired for equality.
 *
 * If the underlying value type is ordered they can be ordered.
 *
 * They can be convered to a dimentioned type with the same dimention vecor,
 *     but differant underling value type.
 *
 * If the dimention vector is all zeros they can conver to and from the underlying daya type.
 *
 */
// NOT multiplicative<T, U> for U an other dimentioned type
//      because Return is not convertible to T!
//
//      dt = dt * dt must be defined as a templete
//
template<typename VT, EdK_DAS_DECLORATIONS0>
class DimentionedType :
	boost::totally_ordered1< DimentionedType<VT, EdK_DAS_REFERANCES0>
	, boost::additive1< DimentionedType<VT, EdK_DAS_REFERANCES0>
	, boost::multiplicative2<DimentionedType<VT, EdK_DAS_REFERANCES0>, VT >
       	> > 
{
public:
    typedef  DimentionedType ThisType;
    typedef  VT UnderlyingValueType;

    UnderlyingValueType value_; /**< The underlying value
                   * Note: Should be private in theory,
		   * but in all types instanciated from
		   * this template need access.
		   */

    /// default constructor
    DimentionedType():value_(0){}

    /// destructor
    /**
     * Only pit here to make it expicit.
     */
    ~DimentionedType(){}


    ///copy constructor
    DimentionedType(const DimentionedType& x):value_(x.value_){}

    /// Convert type of same dimentionality and convertanle underlying types.
    template <class T>
	    DimentionedType (const DimentionedType<T, EdK_DAS_REFERANCES0>& x)
                    :value_(x.value_){}


    /// Suport of fully ordered
    bool operator== (ThisType that) const {
	    return value_ == that.value_;
    }
    bool operator< (ThisType that) const {
	    return value_ < that.value_;
    }

    /// suport for adative
    ThisType operator+= (ThisType that){
	    value_ += that.value_;
	    return *this;
    }
    ThisType operator-= (ThisType that){
	    value_ -= that.value_;
	    return *this;
    }

    ThisType operator*= (UnderlyingValueType that){
	    value_ *= that;
	    return *this;
  } 
    ThisType operator/= (UnderlyingValueType that){
	    value_ /= that;
	    return *this;
    }

    template <EdK_DAS_DECLORATIONS_NO_DEFAULT(_a)>
	    DimentionedType<VT, EdK_DAS_REFERANCES_SUM(_a)
		    > operator*(
			    DimentionedType<VT, 
			    EdK_DAS_REFERANCES(_a)> that
			    ) const {
		    DimentionedType<VT,EdK_DAS_REFERANCES_SUM(_a)> retval;

		    retval.value_ = value_ * that.value_;
		    return retval;
	    }


    template <EdK_DAS_DECLORATIONS_NO_DEFAULT(_a)>
	    DimentionedType<VT, EdK_DAS_REFERANCES_DIF(_a)
		    > operator /(
			    DimentionedType<VT, 
			    EdK_DAS_REFERANCES(_a)> that
			    ) const {
		    DimentionedType<VT,EdK_DAS_REFERANCES_DIF(_a)> retval;

		    retval.value_ = value_ / that.value_;
		    return retval;
	    }


};


// sum the sequence of integers
#define  EdK_DASPP_SUM(s, state, x) state + x 


// compares two dimension symbples 
//  returns true if they are the same 
//  false otherwise, 
//  and fails if on of them is not a dimention symbol.
#define EdK_DAS_COMPARE_DIMENTIONS(x,y) \
	BOOST_PP_EQUAL( \
			BOOST_PP_CAT(EdK_DAS_UID_, x), \
			BOOST_PP_CAT(EdK_DAS_UID_,y))


#define EdK_DAS_GET_DIMENTION_VALUE(r, a, data) \
	BOOST_PP_IIF ( \
			EdK_DAS_COMPARE_DIMENTIONS( \
				BOOST_PP_TUPLE_ELEM(2, 0, data),a), \
			(BOOST_PP_TUPLE_ELEM(2, 1, data) * 60), \
			(0) \
			)



#define EdK_DASPP_EXPAND_DIMENSION_VALUE(_, values, dim) , BOOST_PP_SEQ_FOLD_LEFT( \
		EdK_DASPP_SUM, \
		0, \
		BOOST_PP_SEQ_FOR_EACH( \
			EdK_DAS_GET_DIMENTION_VALUE, \
			dim, \
			values \
			) \
		) 



#define EdK_DAS_MAKE_DIMENSION_VECTOR(dimensions) \
		BOOST_PP_LIST_FOR_EACH( \
				EdK_DASPP_EXPAND_DIMENSION_VALUE, \
				dimensions, \
				EdK_DAS_BASIS \
				)


