#pragma once

#include <vector>
#include <iosfwd>

#include "xlsx_drawings.h"
	
namespace oox {

class external_items;

class xlsx_drawing_context_handle
{
public:
    xlsx_drawing_context_handle(external_items & items);
    ~xlsx_drawing_context_handle();
    
    std::pair<std::wstring, std::wstring> add_drawing_xml(std::wstring const & content, xlsx_drawings_ptr drawings);
    const std::vector<drawing_elm> & content() const;

    friend class xlsx_drawing_context;
private:
    class Impl;
    _CP_PTR(Impl) impl_;
};

class _drawing_state
{
public:
	_drawing_state() 
	{
		isInternal = false; id = shape_id = -1; 
		flipV = flipH = false;  
		memset(image_crop, 0, 4 * sizeof(int));
	}

	external_items::Type	type;
	std::wstring			name;
	std::wstring			description;

	std::wstring			anchor;
	std::wstring			shape;

	std::wstring			image_target;
	int						image_crop[4];
	bool					image_crop_enabled;
	
	int						id;
	int						shape_id;
	
	bool					flipV;
	bool					flipH;
	std::wstring			hyperlink;
	
	bool					isInternal;
};
struct _hlink_desc
{
    std::wstring hId;
    std::wstring hRef;
};

class xlsx_drawing_context
{
public:
    xlsx_drawing_context(xlsx_drawing_context_handle & h);
	~xlsx_drawing_context(){}

	xlsx_drawings_ptr get_drawings();
	bool empty();	
	
	bool start_drawing(int type);	
		void start_image();
		void start_shape(int type);

		void set_id			(long id);
		void set_FlipH		();
		void set_FlipV		();
		void set_shape_id	(int id);

		void set_name		(std::wstring & str);
		void set_description(std::wstring & str);
		
		void set_crop_top	(long val);
		void set_crop_bottom(long val);
		void set_crop_left	(long val);
		void set_crop_right	(long val);

		void set_image		(std::wstring & str);
		void set_anchor		(std::wstring & str);
		void set_properties	(std::wstring & str);
		void set_hyperlink	(std::wstring & str);

		void serialize(std::wostream & stream);

		void serialize_pic(std::wstring rId);	
	void end_drawing();
private:

	std::vector<_drawing_state>		drawing_state;
	
	xlsx_drawing_context_handle	  & handle_;
	xlsx_drawings_ptr				xlsx_drawings_;
	int								count_object;
	
	std::vector<_hlink_desc>		hlinks_;
};

}
