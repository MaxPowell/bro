// This file was automatically generated by bifcl from /home/ubuntu/bro/src/broxygen/broxygen.bif (alternative mode).


#include "broxygen.bif.h"


#line 5 "broxygen.bif"

#include "broxygen/Manager.h"
#include "util.h"

static StringVal* comments_to_val(const vector<string>& comments)
	{
	return new StringVal(implode_string_vector(comments));
	}

#line 22 "broxygen.bif"
Val* BifFunc::bro_get_identifier_comments(Frame* frame, val_list* BiF_ARGS)
	
#line 23 "broxygen.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("get_identifier_comments() takes exactly 1 argument(s)");
		return 0;
		}
	StringVal* name = (StringVal*) ((*BiF_ARGS)[0]->AsStringVal());

#line 23 "broxygen.bif"

	using namespace broxygen;
	IdentifierInfo* d = broxygen_mgr->GetIdentifierInfo(name->CheckString());

	if ( ! d )
		return new StringVal("");

	return comments_to_val(d->GetComments());
	} // end of BifFunc::bro_get_identifier_comments

#line 31 "broxygen.bif"

#line 42 "broxygen.bif"
Val* BifFunc::bro_get_script_comments(Frame* frame, val_list* BiF_ARGS)
	
#line 43 "broxygen.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("get_script_comments() takes exactly 1 argument(s)");
		return 0;
		}
	StringVal* name = (StringVal*) ((*BiF_ARGS)[0]->AsStringVal());

#line 43 "broxygen.bif"

	using namespace broxygen;
	ScriptInfo* d = broxygen_mgr->GetScriptInfo(name->CheckString());

	if ( ! d )
		return new StringVal("");

	return comments_to_val(d->GetComments());
	} // end of BifFunc::bro_get_script_comments

#line 51 "broxygen.bif"

#line 60 "broxygen.bif"
Val* BifFunc::bro_get_package_readme(Frame* frame, val_list* BiF_ARGS)
	
#line 61 "broxygen.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("get_package_readme() takes exactly 1 argument(s)");
		return 0;
		}
	StringVal* name = (StringVal*) ((*BiF_ARGS)[0]->AsStringVal());

#line 61 "broxygen.bif"

	using namespace broxygen;
	PackageInfo* d = broxygen_mgr->GetPackageInfo(name->CheckString());

	if ( ! d )
		return new StringVal("");

	return comments_to_val(d->GetReadme());
	} // end of BifFunc::bro_get_package_readme

#line 69 "broxygen.bif"

#line 79 "broxygen.bif"
Val* BifFunc::bro_get_record_field_comments(Frame* frame, val_list* BiF_ARGS)
	
#line 80 "broxygen.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("get_record_field_comments() takes exactly 1 argument(s)");
		return 0;
		}
	StringVal* name = (StringVal*) ((*BiF_ARGS)[0]->AsStringVal());

#line 80 "broxygen.bif"

	using namespace broxygen;
	string accessor = name->CheckString();
	size_t i = accessor.find('$');

	if ( i > accessor.size() - 2 )
		return new StringVal("");

	string id = accessor.substr(0, i);

	IdentifierInfo* d = broxygen_mgr->GetIdentifierInfo(id);

	if ( ! d )
		return new StringVal("");

	string field = accessor.substr(i + 1);
	return comments_to_val(d->GetFieldComments(field));
	} // end of BifFunc::bro_get_record_field_comments

#line 97 "broxygen.bif"
