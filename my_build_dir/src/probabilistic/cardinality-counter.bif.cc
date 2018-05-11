// This file was automatically generated by bifcl from /home/ubuntu/bro/src/probabilistic/cardinality-counter.bif (alternative mode).


#include "cardinality-counter.bif.h"


#line 3 "cardinality-counter.bif"

#include "probabilistic/CardinalityCounter.h"

using namespace probabilistic;

#line 22 "cardinality-counter.bif"
Val* BifFunc::bro_hll_cardinality_init(Frame* frame, val_list* BiF_ARGS)
	
#line 23 "cardinality-counter.bif"
{
	if ( BiF_ARGS->length() != 2 )
		{
		reporter->Error("hll_cardinality_init() takes exactly 2 argument(s)");
		return 0;
		}
	double err = (double) ((*BiF_ARGS)[0]->AsDouble());
	double confidence = (double) ((*BiF_ARGS)[1]->AsDouble());

#line 23 "cardinality-counter.bif"

	CardinalityCounter* c = new CardinalityCounter(err, confidence);
	CardinalityVal* cv = new CardinalityVal(c);

	return cv;
	} // end of BifFunc::bro_hll_cardinality_init

#line 28 "cardinality-counter.bif"

#line 40 "cardinality-counter.bif"
Val* BifFunc::bro_hll_cardinality_add(Frame* frame, val_list* BiF_ARGS)
	
#line 41 "cardinality-counter.bif"
{
	if ( BiF_ARGS->length() != 2 )
		{
		reporter->Error("hll_cardinality_add() takes exactly 2 argument(s)");
		return 0;
		}
	Val* handle = (Val*) ((*BiF_ARGS)[0]);
	Val* elem = (Val*) ((*BiF_ARGS)[1]);

#line 41 "cardinality-counter.bif"

	CardinalityVal* cv = static_cast<CardinalityVal*>(handle);

	if ( ! cv->Type() && ! cv->Typify(elem->Type()) )
		{
		reporter->Error("failed to set HLL type");
		return new Val(0, TYPE_BOOL);
		}

	else if ( ! same_type(cv->Type(), elem->Type()) )
		{
		reporter->Error("incompatible HLL data type");
		return new Val(0, TYPE_BOOL);
		}

	cv->Add(elem);
	return new Val(1, TYPE_BOOL);
	} // end of BifFunc::bro_hll_cardinality_add

#line 58 "cardinality-counter.bif"

#line 73 "cardinality-counter.bif"
Val* BifFunc::bro_hll_cardinality_merge_into(Frame* frame, val_list* BiF_ARGS)
	
#line 74 "cardinality-counter.bif"
{
	if ( BiF_ARGS->length() != 2 )
		{
		reporter->Error("hll_cardinality_merge_into() takes exactly 2 argument(s)");
		return 0;
		}
	Val* handle1 = (Val*) ((*BiF_ARGS)[0]);
	Val* handle2 = (Val*) ((*BiF_ARGS)[1]);

#line 74 "cardinality-counter.bif"

	CardinalityVal* v1 = static_cast<CardinalityVal*>(handle1);
	CardinalityVal* v2 = static_cast<CardinalityVal*>(handle2);

	if ( (v1->Type() != v2->Type()) && // both 0 is ok
	     (v1->Type() != 0) && // any one 0 also is ok
	     (v2->Type() != 0) &&
	     ! same_type(v1->Type(), v2->Type()) )
		{
		reporter->Error("incompatible HLL types");
		return new Val(0, TYPE_BOOL);
		}

	CardinalityCounter* h1 = v1->Get();
	CardinalityCounter* h2 = v2->Get();

	bool res = h1->Merge(h2);
	if ( ! res )
		{
		reporter->Error("Carinality counters with different parameters cannot be merged");
		return new Val(0, TYPE_BOOL);
		}

	return new Val(1, TYPE_BOOL);
	} // end of BifFunc::bro_hll_cardinality_merge_into

#line 98 "cardinality-counter.bif"

#line 108 "cardinality-counter.bif"
Val* BifFunc::bro_hll_cardinality_estimate(Frame* frame, val_list* BiF_ARGS)
	
#line 109 "cardinality-counter.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("hll_cardinality_estimate() takes exactly 1 argument(s)");
		return 0;
		}
	Val* handle = (Val*) ((*BiF_ARGS)[0]);

#line 109 "cardinality-counter.bif"

	CardinalityVal* cv = static_cast<CardinalityVal*>(handle);
	CardinalityCounter* h = cv->Get();

	double estimate = h->Size();

	return new Val(estimate, TYPE_DOUBLE);
	} // end of BifFunc::bro_hll_cardinality_estimate

#line 116 "cardinality-counter.bif"

#line 126 "cardinality-counter.bif"
Val* BifFunc::bro_hll_cardinality_copy(Frame* frame, val_list* BiF_ARGS)
	
#line 127 "cardinality-counter.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("hll_cardinality_copy() takes exactly 1 argument(s)");
		return 0;
		}
	Val* handle = (Val*) ((*BiF_ARGS)[0]);

#line 127 "cardinality-counter.bif"

	CardinalityVal* cv = static_cast<CardinalityVal*>(handle);
	CardinalityCounter* h = cv->Get();
	CardinalityCounter* h2 = new CardinalityCounter(*h);
	CardinalityVal* out = new CardinalityVal(h2);

	return out;
	} // end of BifFunc::bro_hll_cardinality_copy

#line 134 "cardinality-counter.bif"
