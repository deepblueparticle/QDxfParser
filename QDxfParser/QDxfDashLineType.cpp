#include "QDxfDashLineType.h"


QDxfDashLineType::QDxfDashLineType(void)
{
	m_elementCount = 2;
	m_elementLength.push_back(2.00);
	m_elementLength.push_back(-2.00);
	m_patternLength = 4;
	m_lineTypeName = "DashLine";
	//description = QString::fromLocal8Bit("���߶�");
	m_description = "DashLine";
	
}

QDxfDashLineType::QDxfDashLineType(QString lineTypeName ,QString description):QDxfLineType(lineTypeName,description)
{
	m_elementCount = 2;
	m_elementLength.push_back(2.00);
	m_elementLength.push_back(-2.00);
	m_patternLength = 4;
}


QDxfDashLineType::~QDxfDashLineType(void)
{
}

void QDxfDashLineType::write(QDxfWriter* writer)
{
	writer->writeString(0,QString::fromStdString(c_sLtype));
	writer->writeString(2,m_lineTypeName);
	writer->writeInt(70,m_flag);
	writer->writeString(3,m_description);
	writer->writeInt(72,m_alignment);
	writer->writeInt(73,m_elementCount);
	writer->writeReal(40,m_patternLength);
	Q_FOREACH(double length,m_elementLength)
	{
		writer->writeReal(49,length);
	}
}
