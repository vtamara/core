#pragma once

#include <vector>

#if defined(_WIN32) || defined (_WIN64)
    #include <atlbase.h>
    #include <atlstr.h>
#else
	#include "../../Common/DocxFormat/Source/Base/ASCString.h"
#endif


namespace NSPresentationEditor
{
	class CEffect
	{
	public:
		CString m_strEffect;

	public:
		CEffect() : m_strEffect(_T(""))
		{
		}
		CEffect& operator=(const CEffect& oSrc)
		{
			m_strEffect	= oSrc.m_strEffect;
			return *this;
		}
		CEffect(const CEffect& oSrc)
		{
			*this = oSrc;
		}
		~CEffect()
		{
		}
	};

	class CEffects
	{
	public:
		std::vector<CEffect> m_arEffects;

	public:
		CEffects() : m_arEffects()
		{
		}
		CEffects& operator=(const CEffects& oSrc)
		{
			m_arEffects.insert(m_arEffects.end(), oSrc.m_arEffects.begin(), oSrc.m_arEffects.end());
			return *this;
		}
		CEffects(const CEffects& oSrc)
		{
			*this = oSrc;
		}
		~CEffects()
		{
		}
	};
}