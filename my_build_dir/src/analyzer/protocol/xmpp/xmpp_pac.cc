// This file is automatically generated from /home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp.pac.


#ifdef __clang__
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#include "/home/ubuntu/bro/my_build_dir/src/analyzer/protocol/xmpp/xmpp_pac.h"

namespace binpac {







namespace XMPP {
ContextXMPP::ContextXMPP(XMPP_Conn * connection, XMPP_Flow * flow)
	{
	connection_ = connection;
	flow_ = flow;
	}

ContextXMPP::~ContextXMPP()
	{
	}

XMPP_Conn::XMPP_Conn(XMPPAnalyzer const & bro_analyzer)
	{
	upflow_ = new XMPP_Flow(this, true);
	downflow_ = new XMPP_Flow(this, false);
	bro_analyzer_ = bro_analyzer;

	client_starttls = false;
	
	}

XMPP_Conn::~XMPP_Conn()
	{
	delete upflow_;
	upflow_ = 0;
	delete downflow_;
	downflow_ = 0;
	}

void XMPP_Conn::NewData(bool is_orig, const_byteptr begin, const_byteptr end)
	{
	if ( is_orig )
		upflow_->NewData(begin, end);
	else
		downflow_->NewData(begin, end);
	}

void XMPP_Conn::NewGap(bool is_orig, int gap_length)
	{
	if ( is_orig )
		upflow_->NewGap(gap_length);
	else
		downflow_->NewGap(gap_length);
	}

void XMPP_Conn::FlowEOF(bool is_orig)
	{
	if ( is_orig )
		upflow_->FlowEOF();
	else
		downflow_->FlowEOF();
	}

bool XMPP_Conn::proc_xmpp_token(bool is_orig, bytestring const & name, bytestring const & rest)
	{

		string token = std_str(name);
		// Result will either be text after ":" or original string; this discards the namespace
		string token_no_ns = std_str(name);
		auto offset = token_no_ns.find(":");
		if ( offset != std::string::npos && token_no_ns.length() > offset + 1 )
			token_no_ns = token_no_ns.substr(offset + 1);

		if ( is_orig && token == "stream:stream" )
			// Yup, looks like xmpp...
			bro_analyzer()->ProtocolConfirmation();

		if ( token == "success" || token == "message" || token == "db:result"
		     || token == "db:verify" || token == "presence" )
			// Handshake has passed the phase where we should see StartTLS. Simply skip from hereon...
			bro_analyzer()->SetSkip(true);

		if ( is_orig && ( token == "starttls" || token_no_ns == "starttls" ) )
			client_starttls = true;

		if ( !is_orig && ( token == "proceed" || token_no_ns == "proceed" ) && client_starttls )
			{
			bro_analyzer()->StartTLS();
			BifEvent::generate_xmpp_starttls(bro_analyzer(), bro_analyzer()->Conn());
			}
		else if ( !is_orig && token == "proceed" )
			reporter->Weird(bro_analyzer()->Conn(), "XMPP: proceed without starttls");

		// printf("Processed: %d %s %s %s \n", is_orig, c_str(name), c_str(rest), token_no_ns.c_str());

		return true;
		
	}

RegExMatcher XML_START_re_001("<");

RegExMatcher XML_END_re_002(">");

RegExMatcher XML_NAME_re_003("/?[?:[:alnum:]]+");

RegExMatcher XML_REST_re_004("[^<>]*");

RegExMatcher SPACING_re_005("[ \\r\\n]*");

RegExMatcher CONTENT_re_006("[^<>]*");

XMPP_PDU::XMPP_PDU(bool is_orig)
	{
	val_ = 0;
	is_orig_ = is_orig;
	val__elem_ = 0;
	}

XMPP_PDU::~XMPP_PDU()
	{
	delete val__elem_;
	val__elem_ = 0;
	if ( val() )
		{
		for ( int i = 0; i < (int) val()->size(); ++i )
			{
			XMPP_TOKEN * val__elem_ = (*val_)[i];
			delete val__elem_;
			val__elem_ = 0;
			}
		}
	delete val_;
	}

int XMPP_PDU::Parse(const_byteptr const t_begin_of_data, const_byteptr const t_end_of_data, ContextXMPP * t_context)
	{
	int t_val__arraylength;
	t_val__arraylength = 0;
	val__elem_ = 0;
	int t_val__elem__it;
	t_val__elem__it = 0;
	int t_val__size;
	val_ = new vector<XMPP_TOKEN *>;
	const_byteptr t_val__elem__dataptr = t_begin_of_data;
	for (; /* forever */; ++t_val__elem__it)
		{
		// Check &until(val__elem__dataptr >= end_of_data)
		if ( t_val__elem__dataptr >= t_end_of_data )
			{
			val__elem_ = 0;
			goto end_of_val;
			}
		val__elem_ = new XMPP_TOKEN(is_orig());
		int t_val__elem__size;
		t_val__elem__size = val__elem_->Parse(t_val__elem__dataptr, t_end_of_data, t_context);
		// Evaluate 'let' and 'withinput' fields
		val_->push_back(val__elem_);
		t_val__elem__dataptr += t_val__elem__size;
		BINPAC_ASSERT(t_val__elem__dataptr <= t_end_of_data);
		val__elem_ = 0;
		}
end_of_val: ;
	t_val__size = t_val__elem__dataptr - (t_begin_of_data);
	// Evaluate 'let' and 'withinput' fields
	BINPAC_ASSERT(t_begin_of_data + (t_val__size) <= t_end_of_data);
	return t_val__size;
	}

XMPP_TOKEN::XMPP_TOKEN(bool is_orig)
	{
	is_orig_ = is_orig;
	proc_ = 0;
	}

XMPP_TOKEN::~XMPP_TOKEN()
	{
	name_.free();
	rest_.free();
	tagcontent_.free();
	}

int XMPP_TOKEN::Parse(const_byteptr const t_begin_of_data, const_byteptr const t_end_of_data, ContextXMPP * t_context)
	{
	// Parse "anonymous_field_007"
	bytestring anonymous_field_007_;
	int t_anonymous_field_007_string_length;
	t_anonymous_field_007_string_length = 
		SPACING_re_005.MatchPrefix(
			t_begin_of_data,
			t_end_of_data - t_begin_of_data);
	if ( t_anonymous_field_007_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:11", "[ \\r\\n]*", string((const char *) (t_begin_of_data), (const char *) t_end_of_data).c_str());
		}
	int t_anonymous_field_007__size;
	t_anonymous_field_007__size = t_anonymous_field_007_string_length;
	// Evaluate 'let' and 'withinput' fields
	anonymous_field_007_.free();
	
	const_byteptr const t_dataptr_after_anonymous_field_007 = t_begin_of_data + (t_anonymous_field_007__size);
	BINPAC_ASSERT(t_dataptr_after_anonymous_field_007 <= t_end_of_data);
	// Parse "anonymous_field_008"
	bytestring anonymous_field_008_;
	int t_anonymous_field_008_string_length;
	t_anonymous_field_008_string_length = 
		XML_START_re_001.MatchPrefix(
			t_dataptr_after_anonymous_field_007,
			t_end_of_data - t_dataptr_after_anonymous_field_007);
	if ( t_anonymous_field_008_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:12", "<", string((const char *) (t_dataptr_after_anonymous_field_007), (const char *) t_end_of_data).c_str());
		}
	int t_anonymous_field_008__size;
	t_anonymous_field_008__size = t_anonymous_field_008_string_length;
	// Evaluate 'let' and 'withinput' fields
	anonymous_field_008_.free();
	
	const_byteptr const t_dataptr_after_anonymous_field_008 = t_dataptr_after_anonymous_field_007 + (t_anonymous_field_008__size);
	BINPAC_ASSERT(t_dataptr_after_anonymous_field_008 <= t_end_of_data);
	// Parse "name"
	int t_name_string_length;
	t_name_string_length = 
		XML_NAME_re_003.MatchPrefix(
			t_dataptr_after_anonymous_field_008,
			t_end_of_data - t_dataptr_after_anonymous_field_008);
	if ( t_name_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:13", "/?[?:[:alnum:]]+", string((const char *) (t_dataptr_after_anonymous_field_008), (const char *) t_end_of_data).c_str());
		}
	int t_name__size;
	t_name__size = t_name_string_length;
	// check for negative sizes
	if ( t_name_string_length < 0 )
	throw binpac::ExceptionInvalidStringLength("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:13", t_name_string_length);
	name_.init(t_dataptr_after_anonymous_field_008, t_name_string_length);
	// Evaluate 'let' and 'withinput' fields
	
	const_byteptr const t_dataptr_after_name = t_dataptr_after_anonymous_field_008 + (t_name__size);
	BINPAC_ASSERT(t_dataptr_after_name <= t_end_of_data);
	// Parse "rest"
	int t_rest_string_length;
	t_rest_string_length = 
		XML_REST_re_004.MatchPrefix(
			t_dataptr_after_name,
			t_end_of_data - t_dataptr_after_name);
	if ( t_rest_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:14", "[^<>]*", string((const char *) (t_dataptr_after_name), (const char *) t_end_of_data).c_str());
		}
	int t_rest__size;
	t_rest__size = t_rest_string_length;
	// check for negative sizes
	if ( t_rest_string_length < 0 )
	throw binpac::ExceptionInvalidStringLength("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:14", t_rest_string_length);
	rest_.init(t_dataptr_after_name, t_rest_string_length);
	// Evaluate 'let' and 'withinput' fields
	
	const_byteptr const t_dataptr_after_rest = t_dataptr_after_name + (t_rest__size);
	BINPAC_ASSERT(t_dataptr_after_rest <= t_end_of_data);
	// Parse "anonymous_field_009"
	bytestring anonymous_field_009_;
	int t_anonymous_field_009_string_length;
	t_anonymous_field_009_string_length = 
		XML_END_re_002.MatchPrefix(
			t_dataptr_after_rest,
			t_end_of_data - t_dataptr_after_rest);
	if ( t_anonymous_field_009_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:15", ">", string((const char *) (t_dataptr_after_rest), (const char *) t_end_of_data).c_str());
		}
	int t_anonymous_field_009__size;
	t_anonymous_field_009__size = t_anonymous_field_009_string_length;
	// Evaluate 'let' and 'withinput' fields
	anonymous_field_009_.free();
	
	const_byteptr const t_dataptr_after_anonymous_field_009 = t_dataptr_after_rest + (t_anonymous_field_009__size);
	BINPAC_ASSERT(t_dataptr_after_anonymous_field_009 <= t_end_of_data);
	// Parse "tagcontent"
	int t_tagcontent_string_length;
	t_tagcontent_string_length = 
		CONTENT_re_006.MatchPrefix(
			t_dataptr_after_anonymous_field_009,
			t_end_of_data - t_dataptr_after_anonymous_field_009);
	if ( t_tagcontent_string_length < 0 )
		{
		throw binpac::ExceptionStringMismatch("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:16", "[^<>]*", string((const char *) (t_dataptr_after_anonymous_field_009), (const char *) t_end_of_data).c_str());
		}
	int t_tagcontent__size;
	t_tagcontent__size = t_tagcontent_string_length;
	// check for negative sizes
	if ( t_tagcontent_string_length < 0 )
	throw binpac::ExceptionInvalidStringLength("/home/ubuntu/bro/src/analyzer/protocol/xmpp/xmpp-protocol.pac:16", t_tagcontent_string_length);
	tagcontent_.init(t_dataptr_after_anonymous_field_009, t_tagcontent_string_length);
	// Evaluate 'let' and 'withinput' fields
	
	int t_XMPP_TOKEN__size;
	const_byteptr const t_dataptr_after_tagcontent = t_dataptr_after_anonymous_field_009 + (t_tagcontent__size);
	BINPAC_ASSERT(t_dataptr_after_tagcontent <= t_end_of_data);
	t_XMPP_TOKEN__size = t_dataptr_after_tagcontent - t_begin_of_data;
	// Evaluate 'let' and 'withinput' fields
	proc_ = t_context->connection()->proc_xmpp_token(is_orig(), name(), rest());
	BINPAC_ASSERT(t_begin_of_data + (t_XMPP_TOKEN__size) <= t_end_of_data);
	return t_XMPP_TOKEN__size;
	}

XMPP_Flow::XMPP_Flow(XMPP_Conn * connection, bool is_orig)
	{
	connection_ = connection;
	is_orig_ = is_orig;
	dataunit_ = 0;
	context_ = 0;
	}

XMPP_Flow::~XMPP_Flow()
	{
	delete dataunit_;
	dataunit_ = 0;
	delete context_;
	context_ = 0;
	}

void XMPP_Flow::NewData(const_byteptr t_begin_of_data, const_byteptr t_end_of_data)
	{
	try
		{
		dataunit_ = new XMPP_PDU(is_orig());
		context_ = new ContextXMPP(connection(), this);
		int t_dataunit__size;
		t_dataunit__size = dataunit_->Parse(t_begin_of_data, t_end_of_data, context_);
		// Evaluate 'let' and 'withinput' fields
		delete dataunit_;
		dataunit_ = 0;
		delete context_;
		context_ = 0;
		}
	catch ( binpac::Exception const &e )
		{
		delete dataunit_;
		dataunit_ = 0;
		delete context_;
		context_ = 0;
		throw;
		}
	}

void XMPP_Flow::NewGap(int gap_length)
	{
	}
void XMPP_Flow::FlowEOF()
	{
	}
} // namespace XMPP
}  // namespace binpac
