// This file was automatically generated by bifcl from /home/ubuntu/bro/src/logging/logging.bif (alternative mode).

	BifType::Record::Log::Filter = internal_type("Log::Filter")->AsRecordType();
	BifType::Record::Log::Stream = internal_type("Log::Stream")->AsRecordType();
	BifType::Record::Log::RotationInfo = internal_type("Log::RotationInfo")->AsRecordType();
	(void) new BuiltinFunc(BifFunc::Log::bro___create_stream, "Log::__create_stream", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___remove_stream, "Log::__remove_stream", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___enable_stream, "Log::__enable_stream", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___disable_stream, "Log::__disable_stream", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___add_filter, "Log::__add_filter", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___remove_filter, "Log::__remove_filter", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___write, "Log::__write", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___set_buf, "Log::__set_buf", 0);
	(void) new BuiltinFunc(BifFunc::Log::bro___flush, "Log::__flush", 0);
