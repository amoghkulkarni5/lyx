// -*- C++ -*-
/**
 * \file InsetScript.h
 * This file is part of LyX, the document processor.
 * Licence details can be found in the file COPYING.
 *
 * \author Georg Baum
 *
 * Full author contact details are available in file CREDITS.
 */

#ifndef INSET_SCRIPT_H
#define INSET_SCRIPT_H

#include "InsetText.h"


namespace lyx {

class InsetScriptParams
{
public:
	enum Type {
		Subscript,
		Superscript
	};
	/// \c type defaults to Subscript
	InsetScriptParams();
	///
	void write(std::ostream & os) const;
	///
	void read(Lexer & lex);
	///
	int shift(FontInfo const & font) const;
	///
	Type type;
};


/////////////////////////////////////////////////////////////////////////
//
// InsetScript
//
/////////////////////////////////////////////////////////////////////////

/// The subscript and superscript inset
class InsetScript : public InsetText
{
public:
	///
	InsetScript(Buffer *, InsetScriptParams const & = InsetScriptParams());
	///
	InsetScript(Buffer *, std::string const &);
	///
	~InsetScript();
	///
	static std::string params2string(InsetScriptParams const &);
	///
	static void string2params(std::string const &, InsetScriptParams &);
	///
	InsetScriptParams const & params() const { return params_; }
private:
	///
	InsetCode lyxCode() const { return SCRIPT_CODE; }
	///
	docstring name() const;
	///
	DisplayType display() const;
	///
	void metrics(MetricsInfo &, Dimension &) const;
	///
	void draw(PainterInfo & pi, int x, int y) const;
	///
	virtual void cursorPos(BufferView const & bv,
		CursorSlice const & sl, bool boundary, int & x, int & y) const;
	///
	void write(std::ostream &) const;
	///
	void read(Lexer & lex);
	///
	bool neverIndent() const { return true; }
	///
	virtual bool forcePlainLayout(idx_type = 0) const { return true; }
	///
	virtual bool allowMultiPar() const { return false; }
	///
	virtual bool allowParagraphCustomization(idx_type = 0) const { return false; }
	///
	virtual void validate(LaTeXFeatures &) const;
	///
	int latex(odocstream &, OutputParams const &) const;
	///
	int plaintext(odocstream &, OutputParams const &) const;
	///
	int docbook(odocstream &, OutputParams const &) const;
	///
	docstring xhtml(XHTMLStream &, OutputParams const &) const;
	///
	void edit(Cursor & cur, bool front,
	          EntryDirection entry_from = ENTRY_DIRECTION_IGNORE);
	///
	Inset * editXY(Cursor & cur, int x, int y);
	///
	virtual bool insetAllowed(InsetCode code) const;
	///
	bool getStatus(Cursor &, FuncRequest const &, FuncStatus &) const;
	///
	void doDispatch(Cursor & cur, FuncRequest & cmd);
	///
	docstring toolTip(BufferView const & bv, int x, int y) const;
	///
	Inset * clone() const { return new InsetScript(*this); }
	/// used by the constructors
	void init();
	///
	docstring contextMenu(BufferView const & bv, int x, int y) const;
	///
	friend class InsetScriptParams;

	///
	InsetScriptParams params_;
};


} // namespace lyx

#endif