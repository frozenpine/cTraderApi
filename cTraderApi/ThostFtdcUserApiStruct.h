/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file ThostFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20060106	�Ժ��		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(THOST_FTDCSTRUCT_H)
#define THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ThostFtdcUserApiDataType.h"

///��Ϣ�ַ�
typedef struct CThostFtdcDisseminationField
{
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
} CThostFtdcDisseminationField;

///�û���¼����
typedef struct CThostFtdcReqUserLoginField
{
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��̬����
	TThostFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TThostFtdcIPAddressType	ClientIPAddress;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
} CThostFtdcReqUserLoginField;

///�û���¼Ӧ��
typedef struct CThostFtdcRspUserLoginField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TThostFtdcTimeType	LoginTime;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ϵͳ����
	TThostFtdcSystemNameType	SystemName;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///��󱨵�����
	TThostFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TThostFtdcTimeType	SHFETime;
	///������ʱ��
	TThostFtdcTimeType	DCETime;
	///֣����ʱ��
	TThostFtdcTimeType	CZCETime;
	///�н���ʱ��
	TThostFtdcTimeType	FFEXTime;
	///��Դ����ʱ��
	TThostFtdcTimeType	INETime;
} CThostFtdcRspUserLoginField;

///�û��ǳ�����
typedef struct CThostFtdcUserLogoutField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcUserLogoutField;

///ǿ�ƽ���Ա�˳�
typedef struct CThostFtdcForceUserLogoutField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcForceUserLogoutField;

///�ͻ�����֤����
typedef struct CThostFtdcReqAuthenticateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///��֤��
	TThostFtdcAuthCodeType	AuthCode;
	// App����
	TThostFtdcClientAppIDType AppID;
} CThostFtdcReqAuthenticateField;

///�ͻ�����֤��Ӧ
typedef struct CThostFtdcRspAuthenticateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	// App����
	TThostFtdcClientAppIDType AppID;
} CThostFtdcRspAuthenticateField;

///�ͻ�����֤��Ϣ
typedef struct CThostFtdcAuthenticationInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///ʱ���
	TThostFtdcAuthInfoType TimeStamp;
	///��֤��Ϣ
	TThostFtdcAuthInfoType	AuthInfo;
	///�Ƿ�Ϊ��֤���
	TThostFtdcBoolType	IsResult;
	// App����
	TThostFtdcClientAppIDType AppID;
	// �汾��Ϣ
    UtpCipherVersionType    VerInfo;
} CThostFtdcAuthenticationInfoField;

///����ת�ʱ���ͷ
typedef struct CThostFtdcTransferHeaderField
{
	///�汾�ţ�������1.0
	TThostFtdcVersionType	Version;
	///���״��룬����
	TThostFtdcTradeCodeType	TradeCode;
	///�������ڣ������ʽ��yyyymmdd
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ�䣬�����ʽ��hhmmss
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ�ţ�N/A
	TThostFtdcTradeSerialType	TradeSerial;
	///�ڻ���˾���룬����
	TThostFtdcFutureIDType	FutureID;
	///���д��룬���ݲ�ѯ���еõ�������
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ��룬���ݲ�ѯ���еõ�������
	TThostFtdcBankBrchIDType	BankBrchID;
	///����Ա��N/A
	TThostFtdcOperNoType	OperNo;
	///�����豸���ͣ�N/A
	TThostFtdcDeviceIDType	DeviceID;
	///��¼����N/A
	TThostFtdcRecordNumType	RecordNum;
	///�Ự��ţ�N/A
	TThostFtdcSessionIDType	SessionID;
	///�����ţ�N/A
	TThostFtdcRequestIDType	RequestID;
} CThostFtdcTransferHeaderField;

///�����ʽ�ת�ڻ�����TradeCode=202001
typedef struct CThostFtdcTransferBankToFutureReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TThostFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TThostFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferBankToFutureReqField;

///�����ʽ�ת�ڻ�������Ӧ
typedef struct CThostFtdcTransferBankToFutureRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TThostFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TThostFtdcMoneyType	CustFee;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferBankToFutureRspField;

///�ڻ��ʽ�ת��������TradeCode=202002
typedef struct CThostFtdcTransferFutureToBankReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TThostFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TThostFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferFutureToBankReqField;

///�ڻ��ʽ�ת����������Ӧ
typedef struct CThostFtdcTransferFutureToBankRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TThostFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TThostFtdcMoneyType	CustFee;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferFutureToBankRspField;

///��ѯ�����ʽ�����TradeCode=204002
typedef struct CThostFtdcTransferQryBankReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�����־
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferQryBankReqField;

///��ѯ�����ʽ�������Ӧ
typedef struct CThostFtdcTransferQryBankRspField
{
	///��Ӧ����
	TThostFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TThostFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
	///�������
	TThostFtdcMoneyType	TradeAmt;
	///���п������
	TThostFtdcMoneyType	UseAmt;
	///���п�ȡ���
	TThostFtdcMoneyType	FetchAmt;
	///����
	TThostFtdcCurrencyCodeType	CurrencyCode;
} CThostFtdcTransferQryBankRspField;

///��ѯ���н�����ϸ����TradeCode=204999
typedef struct CThostFtdcTransferQryDetailReqField
{
	///�ڻ��ʽ��˻�
	TThostFtdcAccountIDType	FutureAccount;
} CThostFtdcTransferQryDetailReqField;

///��ѯ���н�����ϸ������Ӧ
typedef struct CThostFtdcTransferQryDetailRspField
{
	///��������
	TThostFtdcDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///���״���
	TThostFtdcTradeCodeType	TradeCode;
	///�ڻ���ˮ��
	TThostFtdcTradeSerialNoType	FutureSerial;
	///�ڻ���˾����
	TThostFtdcFutureIDType	FutureID;
	///�ʽ��ʺ�
	TThostFtdcFutureAccountType	FutureAccount;
	///������ˮ��
	TThostFtdcTradeSerialNoType	BankSerial;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///�����˺�
	TThostFtdcBankAccountType	BankAccount;
	///֤������
	TThostFtdcCertCodeType	CertCode;
	///���Ҵ���
	TThostFtdcCurrencyCodeType	CurrencyCode;
	///�������
	TThostFtdcMoneyType	TxAmount;
	///��Ч��־
	TThostFtdcTransferValidFlagType	Flag;
} CThostFtdcTransferQryDetailRspField;

///��Ӧ��Ϣ
typedef struct CThostFtdcRspInfoField
{
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcRspInfoField;

///������
typedef struct CThostFtdcExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������
	TThostFtdcExchangeNameType	ExchangeName;
	///����������
	TThostFtdcExchangePropertyType	ExchangeProperty;
} CThostFtdcExchangeField;

///��Ʒ
typedef struct CThostFtdcProductField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Ʒ����
	TThostFtdcProductNameType	ProductName;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
	///��Լ��������
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TThostFtdcPriceType	PriceTick;
	///�м۵�����µ���
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///�ֲ�����
	TThostFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TThostFtdcPositionDateTypeType	PositionDateType;
	///ƽ�ִ�������
	TThostFtdcCloseDealTypeType	CloseDealType;
	///���ױ�������
	TThostFtdcCurrencyIDType	TradeCurrencyID;
	///��Ѻ�ʽ���÷�Χ
	TThostFtdcMortgageFundUseRangeType	MortgageFundUseRange;
	///��������Ʒ����
	TThostFtdcInstrumentIDType	ExchangeProductID;
	///��Լ������Ʒ����
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
} CThostFtdcProductField;

///��Լ
typedef struct CThostFtdcInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentNameType	InstrumentName;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
	///�������
	TThostFtdcYearType	DeliveryYear;
	///������
	TThostFtdcMonthType	DeliveryMonth;
	///�м۵�����µ���
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TThostFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TThostFtdcVolumeType	MinLimitOrderVolume;
	///��Լ��������
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TThostFtdcPriceType	PriceTick;
	///������
	TThostFtdcDateType	CreateDate;
	///������
	TThostFtdcDateType	OpenDate;
	///������
	TThostFtdcDateType	ExpireDate;
	///��ʼ������
	TThostFtdcDateType	StartDelivDate;
	///����������
	TThostFtdcDateType	EndDelivDate;
	///��Լ��������״̬
	TThostFtdcInstLifePhaseType	InstLifePhase;
	///��ǰ�Ƿ���
	TThostFtdcBoolType	IsTrading;
	///�ֲ�����
	TThostFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TThostFtdcPositionDateTypeType	PositionDateType;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatio;
	///�Ƿ�ʹ�ô��߱�֤���㷨
	TThostFtdcMaxMarginSideAlgorithmType	MaxMarginSideAlgorithm;
	///������Ʒ����
	TThostFtdcInstrumentIDType	UnderlyingInstrID;
	///ִ�м�
	TThostFtdcPriceType	StrikePrice;
	///��Ȩ����
	TThostFtdcOptionsTypeType	OptionsType;
	///��Լ������Ʒ����
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�������
	TThostFtdcCombinationTypeType	CombinationType;
} CThostFtdcInstrumentField;

///���͹�˾
typedef struct CThostFtdcBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾���
	TThostFtdcBrokerAbbrType	BrokerAbbr;
	///���͹�˾����
	TThostFtdcBrokerNameType	BrokerName;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
} CThostFtdcBrokerField;

///����������Ա
typedef struct CThostFtdcTraderField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ����
	TThostFtdcInstallCountType	InstallCount;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcTraderField;

///Ͷ����
typedef struct CThostFtdcInvestorField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TThostFtdcPartyNameType	InvestorName;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ֻ�
	TThostFtdcMobileType	Mobile;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
} CThostFtdcInvestorField;

///���ױ���
typedef struct CThostFtdcTradingCodeField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
} CThostFtdcTradingCodeField;

///��Ա����;��͹�˾������ձ�
typedef struct CThostFtdcPartBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
} CThostFtdcPartBrokerField;

///�����û�
typedef struct CThostFtdcSuperUserField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û�����
	TThostFtdcUserNameType	UserName;
	///����
	TThostFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
} CThostFtdcSuperUserField;

///�����û�����Ȩ��
typedef struct CThostFtdcSuperUserFunctionField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���ܴ���
	TThostFtdcFunctionCodeType	FunctionCode;
} CThostFtdcSuperUserFunctionField;

///Ͷ������
typedef struct CThostFtdcInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
} CThostFtdcInvestorGroupField;

///�ʽ��˻�
typedef struct CThostFtdcTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TThostFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TThostFtdcMoneyType	PreCredit;
	///�ϴδ���
	TThostFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///��Ϣ����
	TThostFtdcMoneyType	InterestBase;
	///��Ϣ����
	TThostFtdcMoneyType	Interest;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TThostFtdcMoneyType	WithdrawQuota;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ö��
	TThostFtdcMoneyType	Credit;
	///��Ѻ���
	TThostFtdcMoneyType	Mortgage;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///�����ڻ�����׼����
	TThostFtdcMoneyType	ReserveBalance;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ϴλ���������
	TThostFtdcMoneyType	PreFundMortgageIn;
	///�ϴλ����ʳ����
	TThostFtdcMoneyType	PreFundMortgageOut;
	///����������
	TThostFtdcMoneyType	FundMortgageIn;
	///�����ʳ����
	TThostFtdcMoneyType	FundMortgageOut;
	///������Ѻ���
	TThostFtdcMoneyType	FundMortgageAvailable;
	///����Ѻ���ҽ��
	TThostFtdcMoneyType	MortgageableFund;
	///�����Ʒռ�ñ�֤��
	TThostFtdcMoneyType	SpecProductMargin;
	///�����Ʒ���ᱣ֤��
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///�����Ʒ������
	TThostFtdcMoneyType	SpecProductCommission;
	///�����Ʒ����������
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///�����Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///�����Ʒƽ��ӯ��
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///�����Ʒ��������֤��
	TThostFtdcMoneyType	SpecProductExchangeMargin;
} CThostFtdcTradingAccountField;

///Ͷ���ֲ߳�
typedef struct CThostFtdcInvestorPositionField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TThostFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TThostFtdcVolumeType	YdPosition;
	///���ճֲ�
	TThostFtdcVolumeType	Position;
	///��ͷ����
	TThostFtdcVolumeType	LongFrozen;
	///��ͷ����
	TThostFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TThostFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TThostFtdcMoneyType	ShortFrozenAmount;
	///������
	TThostFtdcVolumeType	OpenVolume;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///���ֽ��
	TThostFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TThostFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TThostFtdcMoneyType	OpenCost;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TThostFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TThostFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TThostFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TThostFtdcVolumeType	TodayPosition;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///ִ�ж���
	TThostFtdcVolumeType	StrikeFrozen;
	///ִ�ж�����
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TThostFtdcVolumeType	AbandonFrozen;
} CThostFtdcInvestorPositionField;

///��Լ��֤����
typedef struct CThostFtdcInstrumentMarginRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
} CThostFtdcInstrumentMarginRateField;

///��Լ��������
typedef struct CThostFtdcInstrumentCommissionRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
} CThostFtdcInstrumentCommissionRateField;

///�������
typedef struct CThostFtdcDepthMarketDataField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
	///������
	TThostFtdcPriceType	ClosePrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///�����һ
	TThostFtdcPriceType	BidPrice1;
	///������һ
	TThostFtdcVolumeType	BidVolume1;
	///������һ
	TThostFtdcPriceType	AskPrice1;
	///������һ
	TThostFtdcVolumeType	AskVolume1;
	///����۶�
	TThostFtdcPriceType	BidPrice2;
	///��������
	TThostFtdcVolumeType	BidVolume2;
	///�����۶�
	TThostFtdcPriceType	AskPrice2;
	///��������
	TThostFtdcVolumeType	AskVolume2;
	///�������
	TThostFtdcPriceType	BidPrice3;
	///��������
	TThostFtdcVolumeType	BidVolume3;
	///��������
	TThostFtdcPriceType	AskPrice3;
	///��������
	TThostFtdcVolumeType	AskVolume3;
	///�������
	TThostFtdcPriceType	BidPrice4;
	///��������
	TThostFtdcVolumeType	BidVolume4;
	///��������
	TThostFtdcPriceType	AskPrice4;
	///��������
	TThostFtdcVolumeType	AskVolume4;
	///�������
	TThostFtdcPriceType	BidPrice5;
	///��������
	TThostFtdcVolumeType	BidVolume5;
	///��������
	TThostFtdcPriceType	AskPrice5;
	///��������
	TThostFtdcVolumeType	AskVolume5;
	///���վ���
	TThostFtdcPriceType	AveragePrice;
	///ҵ������
	TThostFtdcDateType	ActionDay;
} CThostFtdcDepthMarketDataField;

///Ͷ���ߺ�Լ����Ȩ��
typedef struct CThostFtdcInstrumentTradingRightField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
} CThostFtdcInstrumentTradingRightField;

///���͹�˾�û�
typedef struct CThostFtdcBrokerUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û�����
	TThostFtdcUserNameType	UserName;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///�Ƿ�ʹ������
	TThostFtdcBoolType	IsUsingOTP;
} CThostFtdcBrokerUserField;

///���͹�˾�û�����
typedef struct CThostFtdcBrokerUserPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcPasswordType	Password;
} CThostFtdcBrokerUserPasswordField;

///���͹�˾�û�����Ȩ��
typedef struct CThostFtdcBrokerUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���͹�˾���ܴ���
	TThostFtdcBrokerFunctionCodeType	BrokerFunctionCode;
} CThostFtdcBrokerUserFunctionField;

///����������Ա���̻�
typedef struct CThostFtdcTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TThostFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TThostFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�����������
	TThostFtdcDateType	ConnectDate;
	///�������ʱ��
	TThostFtdcTimeType	ConnectTime;
	///��������
	TThostFtdcDateType	StartDate;
	///����ʱ��
	TThostFtdcTimeType	StartTime;
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TThostFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
} CThostFtdcTraderOfferField;

///Ͷ���߽�����
typedef struct CThostFtdcSettlementInfoField
{
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TThostFtdcContentType	Content;
} CThostFtdcSettlementInfoField;

///��Լ��֤���ʵ���
typedef struct CThostFtdcInstrumentMarginRateAdjustField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
} CThostFtdcInstrumentMarginRateAdjustField;

///��������֤����
typedef struct CThostFtdcExchangeMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
} CThostFtdcExchangeMarginRateField;

///��������֤���ʵ���
typedef struct CThostFtdcExchangeMarginRateAdjustField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///���潻����Ͷ���߶�ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///���潻����Ͷ���߶�ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///���潻����Ͷ���߿�ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///���潻����Ͷ���߿�ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///��������ͷ��֤����
	TThostFtdcRatioType	ExchLongMarginRatioByMoney;
	///��������ͷ��֤���
	TThostFtdcMoneyType	ExchLongMarginRatioByVolume;
	///��������ͷ��֤����
	TThostFtdcRatioType	ExchShortMarginRatioByMoney;
	///��������ͷ��֤���
	TThostFtdcMoneyType	ExchShortMarginRatioByVolume;
	///�����潻����Ͷ���߶�ͷ��֤����
	TThostFtdcRatioType	NoLongMarginRatioByMoney;
	///�����潻����Ͷ���߶�ͷ��֤���
	TThostFtdcMoneyType	NoLongMarginRatioByVolume;
	///�����潻����Ͷ���߿�ͷ��֤����
	TThostFtdcRatioType	NoShortMarginRatioByMoney;
	///�����潻����Ͷ���߿�ͷ��֤���
	TThostFtdcMoneyType	NoShortMarginRatioByVolume;
} CThostFtdcExchangeMarginRateAdjustField;

///����
typedef struct CThostFtdcExchangeRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Դ���ֵ�λ����
	TThostFtdcCurrencyUnitType	FromCurrencyUnit;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
	///����
	TThostFtdcExchangeRateType	ExchangeRate;
} CThostFtdcExchangeRateField;

///��������
typedef struct CThostFtdcSettlementRefField
{
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
} CThostFtdcSettlementRefField;

///��ǰʱ��
typedef struct CThostFtdcCurrentTimeField
{
	///��ǰ����
	TThostFtdcDateType	CurrDate;
	///��ǰʱ��
	TThostFtdcTimeType	CurrTime;
	///��ǰʱ�䣨���룩
	TThostFtdcMillisecType	CurrMillisec;
	///ҵ������
	TThostFtdcDateType	ActionDay;
} CThostFtdcCurrentTimeField;

///ͨѶ�׶�
typedef struct CThostFtdcCommPhaseField
{
	///������
	TThostFtdcDateType	TradingDay;
	///ͨѶʱ�α��
	TThostFtdcCommPhaseNoType	CommPhaseNo;
	///ϵͳ���
	TThostFtdcSystemIDType	SystemID;
} CThostFtdcCommPhaseField;

///��¼��Ϣ
typedef struct CThostFtdcLoginInfoField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼����
	TThostFtdcDateType	LoginDate;
	///��¼ʱ��
	TThostFtdcTimeType	LoginTime;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///ϵͳ����
	TThostFtdcSystemNameType	SystemName;
	///����
	TThostFtdcPasswordType	Password;
	///��󱨵�����
	TThostFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TThostFtdcTimeType	SHFETime;
	///������ʱ��
	TThostFtdcTimeType	DCETime;
	///֣����ʱ��
	TThostFtdcTimeType	CZCETime;
	///�н���ʱ��
	TThostFtdcTimeType	FFEXTime;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��̬����
	TThostFtdcPasswordType	OneTimePassword;
	///��Դ����ʱ��
	TThostFtdcTimeType	INETime;
	///��ѯʱ�Ƿ���Ҫ����
	TThostFtdcBoolType	IsQryControl;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
} CThostFtdcLoginInfoField;

///��¼��Ϣ
typedef struct CThostFtdcLogoutAllField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///ϵͳ����
	TThostFtdcSystemNameType	SystemName;
} CThostFtdcLogoutAllField;

///ǰ��״̬
typedef struct CThostFtdcFrontStatusField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
} CThostFtdcFrontStatusField;

///�û�������
typedef struct CThostFtdcUserPasswordUpdateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
} CThostFtdcUserPasswordUpdateField;

///���뱨��
typedef struct CThostFtdcInputOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TThostFtdcBoolType	UserForceClose;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputOrderField;

///����
typedef struct CThostFtdcOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�û�ǿ����־
	TThostFtdcBoolType	UserForceClose;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///֣�����ɽ�����
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcOrderField;

///����������
typedef struct CThostFtdcExchangeOrderField
{
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeOrderField;

///��������������ʧ��
typedef struct CThostFtdcExchangeOrderInsertErrorField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcExchangeOrderInsertErrorField;

///���뱨������
typedef struct CThostFtdcInputOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputOrderActionField;

///��������
typedef struct CThostFtdcOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcOrderActionField;

///��������������
typedef struct CThostFtdcExchangeOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeOrderActionField;

///��������������ʧ��
typedef struct CThostFtdcExchangeOrderActionErrorField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcExchangeOrderActionErrorField;

///�������ɽ�
typedef struct CThostFtdcExchangeTradeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��������
	TThostFtdcDirectionType	Direction;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���׽�ɫ
	TThostFtdcTradingRoleType	TradingRole;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TThostFtdcPriceType	Price;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TThostFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TThostFtdcTimeType	TradeTime;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TThostFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�ɽ���Դ
	TThostFtdcTradeSourceType	TradeSource;
} CThostFtdcExchangeTradeField;

///�ɽ�
typedef struct CThostFtdcTradeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��������
	TThostFtdcDirectionType	Direction;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���׽�ɫ
	TThostFtdcTradingRoleType	TradingRole;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TThostFtdcPriceType	Price;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TThostFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TThostFtdcTimeType	TradeTime;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TThostFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///�ɽ���Դ
	TThostFtdcTradeSourceType	TradeSource;
} CThostFtdcTradeField;

///�û��Ự
typedef struct CThostFtdcUserSessionField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼����
	TThostFtdcDateType	LoginDate;
	///��¼ʱ��
	TThostFtdcTimeType	LoginTime;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///��¼��ע
	TThostFtdcLoginRemarkType	LoginRemark;
} CThostFtdcUserSessionField;

///��ѯ��󱨵�����
typedef struct CThostFtdcQueryMaxOrderVolumeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�������������
	TThostFtdcVolumeType	MaxVolume;
} CThostFtdcQueryMaxOrderVolumeField;

///Ͷ���߽�����ȷ����Ϣ
typedef struct CThostFtdcSettlementInfoConfirmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ȷ������
	TThostFtdcDateType	ConfirmDate;
	///ȷ��ʱ��
	TThostFtdcTimeType	ConfirmTime;
} CThostFtdcSettlementInfoConfirmField;

///�����ͬ��
typedef struct CThostFtdcSyncDepositField
{
	///�������ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����
	TThostFtdcMoneyType	Deposit;
	///�Ƿ�ǿ�ƽ���
	TThostFtdcBoolType	IsForce;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcSyncDepositField;

///������Ѻͬ��
typedef struct CThostFtdcSyncFundMortgageField
{
	///������Ѻ��ˮ��
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///��Ѻ���
	TThostFtdcMoneyType	MortgageAmount;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
} CThostFtdcSyncFundMortgageField;

///���ļ��ʽ�ת��
typedef struct CThostFtdcTransFundField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����ĺ��ĵ�ַ
	TThostFtdcAddressAndPortType DepositKernel;
	///���ĺ��ĵ�ַ
	TThostFtdcAddressAndPortType IncomingKernel;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�˽��
	TThostFtdcMoneyType	Amount;
} CThostFtdcTransFundField;

///���͹�˾ͬ��
typedef struct CThostFtdcBrokerSyncField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcBrokerSyncField;

///����ͬ���е�Ͷ����
typedef struct CThostFtdcSyncingInvestorField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TThostFtdcPartyNameType	InvestorName;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ֻ�
	TThostFtdcMobileType	Mobile;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
} CThostFtdcSyncingInvestorField;

///����ͬ���еĽ��״���
typedef struct CThostFtdcSyncingTradingCodeField
{
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
} CThostFtdcSyncingTradingCodeField;

///����ͬ���е�Ͷ���߷���
typedef struct CThostFtdcSyncingInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TThostFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
} CThostFtdcSyncingInvestorGroupField;

///����ͬ���еĽ����˺�
typedef struct CThostFtdcSyncingTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TThostFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TThostFtdcMoneyType	PreCredit;
	///�ϴδ���
	TThostFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///��Ϣ����
	TThostFtdcMoneyType	InterestBase;
	///��Ϣ����
	TThostFtdcMoneyType	Interest;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TThostFtdcMoneyType	WithdrawQuota;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ö��
	TThostFtdcMoneyType	Credit;
	///��Ѻ���
	TThostFtdcMoneyType	Mortgage;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TThostFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	///�����ڻ�����׼����
	TThostFtdcMoneyType	ReserveBalance;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ϴλ���������
	TThostFtdcMoneyType	PreFundMortgageIn;
	///�ϴλ����ʳ����
	TThostFtdcMoneyType	PreFundMortgageOut;
	///����������
	TThostFtdcMoneyType	FundMortgageIn;
	///�����ʳ����
	TThostFtdcMoneyType	FundMortgageOut;
	///������Ѻ���
	TThostFtdcMoneyType	FundMortgageAvailable;
	///����Ѻ���ҽ��
	TThostFtdcMoneyType	MortgageableFund;
	///�����Ʒռ�ñ�֤��
	TThostFtdcMoneyType	SpecProductMargin;
	///�����Ʒ���ᱣ֤��
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	///�����Ʒ������
	TThostFtdcMoneyType	SpecProductCommission;
	///�����Ʒ����������
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	///�����Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfit;
	///�����Ʒƽ��ӯ��
	TThostFtdcMoneyType	SpecProductCloseProfit;
	///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	///�����Ʒ��������֤��
	TThostFtdcMoneyType	SpecProductExchangeMargin;
} CThostFtdcSyncingTradingAccountField;

///����ͬ���е�Ͷ���ֲ߳�
typedef struct CThostFtdcSyncingInvestorPositionField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TThostFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TThostFtdcVolumeType	YdPosition;
	///���ճֲ�
	TThostFtdcVolumeType	Position;
	///��ͷ����
	TThostFtdcVolumeType	LongFrozen;
	///��ͷ����
	TThostFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TThostFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TThostFtdcMoneyType	ShortFrozenAmount;
	///������
	TThostFtdcVolumeType	OpenVolume;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///���ֽ��
	TThostFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TThostFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TThostFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///������
	TThostFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TThostFtdcMoneyType	OpenCost;
	///��������֤��
	TThostFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TThostFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TThostFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TThostFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TThostFtdcVolumeType	TodayPosition;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///ִ�ж���
	TThostFtdcVolumeType	StrikeFrozen;
	///ִ�ж�����
	TThostFtdcMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TThostFtdcVolumeType	AbandonFrozen;
} CThostFtdcSyncingInvestorPositionField;

///����ͬ���еĺ�Լ��֤����
typedef struct CThostFtdcSyncingInstrumentMarginRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TThostFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TThostFtdcBoolType	IsRelative;
} CThostFtdcSyncingInstrumentMarginRateField;

///����ͬ���еĺ�Լ��������
typedef struct CThostFtdcSyncingInstrumentCommissionRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
} CThostFtdcSyncingInstrumentCommissionRateField;

///����ͬ���еĺ�Լ����Ȩ��
typedef struct CThostFtdcSyncingInstrumentTradingRightField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
} CThostFtdcSyncingInstrumentTradingRightField;

///��ѯ����
typedef struct CThostFtdcQryOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
} CThostFtdcQryOrderField;

///��ѯ�ɽ�
typedef struct CThostFtdcQryTradeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///��ʼʱ��
	TThostFtdcTimeType	TradeTimeStart;
	///����ʱ��
	TThostFtdcTimeType	TradeTimeEnd;
} CThostFtdcQryTradeField;

///��ѯͶ���ֲ߳�
typedef struct CThostFtdcQryInvestorPositionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryInvestorPositionField;

///��ѯ�ʽ��˻�
typedef struct CThostFtdcQryTradingAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcQryTradingAccountField;

///��ѯͶ����
typedef struct CThostFtdcQryInvestorField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryInvestorField;

///��ѯ���ױ���
typedef struct CThostFtdcQryTradingCodeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///���ױ�������
	TThostFtdcClientIDTypeType	ClientIDType;
} CThostFtdcQryTradingCodeField;

///��ѯͶ������
typedef struct CThostFtdcQryInvestorGroupField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcQryInvestorGroupField;

///��ѯ��Լ��֤����
typedef struct CThostFtdcQryInstrumentMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
} CThostFtdcQryInstrumentMarginRateField;

///��ѯ��������
typedef struct CThostFtdcQryInstrumentCommissionRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryInstrumentCommissionRateField;

///��ѯ��Լ����Ȩ��
typedef struct CThostFtdcQryInstrumentTradingRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryInstrumentTradingRightField;

///��ѯ���͹�˾
typedef struct CThostFtdcQryBrokerField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcQryBrokerField;

///��ѯ����Ա
typedef struct CThostFtdcQryTraderField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryTraderField;

///��ѯ�����û�����Ȩ��
typedef struct CThostFtdcQrySuperUserFunctionField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQrySuperUserFunctionField;

///��ѯ�û��Ự
typedef struct CThostFtdcQryUserSessionField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQryUserSessionField;

///��ѯ���͹�˾��Ա����
typedef struct CThostFtdcQryPartBrokerField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
} CThostFtdcQryPartBrokerField;

///��ѯǰ��״̬
typedef struct CThostFtdcQryFrontStatusField
{
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
} CThostFtdcQryFrontStatusField;

///��ѯ����������
typedef struct CThostFtdcQryExchangeOrderField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeOrderField;

///��ѯ��������
typedef struct CThostFtdcQryOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryOrderActionField;

///��ѯ��������������
typedef struct CThostFtdcQryExchangeOrderActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeOrderActionField;

///��ѯ�����û�
typedef struct CThostFtdcQrySuperUserField
{
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQrySuperUserField;

///��ѯ������
typedef struct CThostFtdcQryExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryExchangeField;

///��ѯ��Ʒ
typedef struct CThostFtdcQryProductField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///��Ʒ����
	TThostFtdcProductClassType	ProductClass;
} CThostFtdcQryProductField;

///��ѯ��Լ
typedef struct CThostFtdcQryInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
} CThostFtdcQryInstrumentField;

///��ѯ����
typedef struct CThostFtdcQryDepthMarketDataField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryDepthMarketDataField;

///��ѯ���͹�˾�û�
typedef struct CThostFtdcQryBrokerUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQryBrokerUserField;

///��ѯ���͹�˾�û�Ȩ��
typedef struct CThostFtdcQryBrokerUserFunctionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQryBrokerUserFunctionField;

///��ѯ����Ա���̻�
typedef struct CThostFtdcQryTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryTraderOfferField;

///��ѯ�������ˮ
typedef struct CThostFtdcQrySyncDepositField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�������ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
} CThostFtdcQrySyncDepositField;

///��ѯͶ���߽�����
typedef struct CThostFtdcQrySettlementInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������
	TThostFtdcDateType	TradingDay;
} CThostFtdcQrySettlementInfoField;

///��ѯ��������֤����
typedef struct CThostFtdcQryExchangeMarginRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
} CThostFtdcQryExchangeMarginRateField;

///��ѯ������������֤����
typedef struct CThostFtdcQryExchangeMarginRateAdjustField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
} CThostFtdcQryExchangeMarginRateAdjustField;

///��ѯ����
typedef struct CThostFtdcQryExchangeRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Դ����
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///Ŀ�����
	TThostFtdcCurrencyIDType	ToCurrencyID;
} CThostFtdcQryExchangeRateField;

///��ѯ������Ѻ��ˮ
typedef struct CThostFtdcQrySyncFundMortgageField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///������Ѻ��ˮ��
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
} CThostFtdcQrySyncFundMortgageField;

///��ѯ����
typedef struct CThostFtdcQryHisOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
} CThostFtdcQryHisOrderField;

///��ǰ��Ȩ��Լ��С��֤��
typedef struct CThostFtdcOptionInstrMiniMarginField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��λ���֣���Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	MinMargin;
	///ȡֵ��ʽ
	TThostFtdcValueMethodType	ValueMethod;
	///�Ƿ���潻������ȡ
	TThostFtdcBoolType	IsRelative;
} CThostFtdcOptionInstrMiniMarginField;

///��ǰ��Ȩ��Լ��֤�����ϵ��
typedef struct CThostFtdcOptionInstrMarginAdjustField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	///Ͷ����ͷ��֤�����ϵ��
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	///��ֵ��ͷ��֤�����ϵ��
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	///������ͷ��֤�����ϵ��
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	///������ͷ��֤�����ϵ��
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	///�Ƿ���潻������ȡ
	TThostFtdcBoolType	IsRelative;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	///�����̿�ͷ��֤�����ϵ��
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
} CThostFtdcOptionInstrMarginAdjustField;

///��ǰ��Ȩ��Լ�����ѵ���ϸ����
typedef struct CThostFtdcOptionInstrCommRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TThostFtdcRatioType	StrikeRatioByMoney;
	///ִ��������
	TThostFtdcRatioType	StrikeRatioByVolume;
} CThostFtdcOptionInstrCommRateField;

///��Ȩ���׳ɱ�
typedef struct CThostFtdcOptionInstrTradeCostField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Լ��֤�𲻱䲿��
	TThostFtdcMoneyType	FixedMargin;
	///��Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	MiniMargin;
	///��Ȩ��ԼȨ����
	TThostFtdcMoneyType	Royalty;
	///��������Ȩ��Լ��֤�𲻱䲿��
	TThostFtdcMoneyType	ExchFixedMargin;
	///��������Ȩ��Լ��С��֤��
	TThostFtdcMoneyType	ExchMiniMargin;
} CThostFtdcOptionInstrTradeCostField;

///��Ȩ���׳ɱ���ѯ
typedef struct CThostFtdcQryOptionInstrTradeCostField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Լ����
	TThostFtdcPriceType	InputPrice;
	///��ļ۸�,��0����������
	TThostFtdcPriceType	UnderlyingPrice;
} CThostFtdcQryOptionInstrTradeCostField;

///��Ȩ�������ʲ�ѯ
typedef struct CThostFtdcQryOptionInstrCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryOptionInstrCommRateField;

///��ָ�ֻ�ָ��
typedef struct CThostFtdcIndexPriceField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ָ���ֻ����̼�
	TThostFtdcPriceType	ClosePrice;
} CThostFtdcIndexPriceField;

///�����ִ������
typedef struct CThostFtdcInputExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputExecOrderField;

///����ִ���������
typedef struct CThostFtdcInputExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputExecOrderActionField;

///ִ������
typedef struct CThostFtdcExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///ִ�������ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///ִ�н��
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerExecOrderSeq;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExecOrderField;

///ִ���������
typedef struct CThostFtdcExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExecOrderActionField;

///ִ�������ѯ
typedef struct CThostFtdcQryExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
} CThostFtdcQryExecOrderField;

///������ִ��������Ϣ
typedef struct CThostFtdcExchangeExecOrderField
{
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///ִ�������ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///ִ��������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///ִ�н��
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeExecOrderField;

///������ִ�������ѯ
typedef struct CThostFtdcQryExchangeExecOrderField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeExecOrderField;

///ִ�����������ѯ
typedef struct CThostFtdcQryExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryExecOrderActionField;

///������ִ���������
typedef struct CThostFtdcExchangeExecOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ִ��������
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeExecOrderActionField;

///������ִ�����������ѯ
typedef struct CThostFtdcQryExchangeExecOrderActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeExecOrderActionField;

///����ִ������
typedef struct CThostFtdcErrExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///ִ������
	TThostFtdcActionTypeType	ActionType;
	///����ͷ������ĳֲַ���
	TThostFtdcPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcErrExecOrderField;

///��ѯ����ִ������
typedef struct CThostFtdcQryErrExecOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryErrExecOrderField;

///����ִ���������
typedef struct CThostFtdcErrExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ�������������
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///ִ����������
	TThostFtdcOrderRefType	ExecOrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///ִ������������
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcErrExecOrderActionField;

///��ѯ����ִ���������
typedef struct CThostFtdcQryErrExecOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryErrExecOrderActionField;

///Ͷ������Ȩ��Լ����Ȩ��
typedef struct CThostFtdcOptionInstrTradingRightField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����Ȩ��
	TThostFtdcTradingRightType	TradingRight;
} CThostFtdcOptionInstrTradingRightField;

///��ѯ��Ȩ��Լ����Ȩ��
typedef struct CThostFtdcQryOptionInstrTradingRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
} CThostFtdcQryOptionInstrTradingRightField;

///�����ѯ��
typedef struct CThostFtdcInputForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ѯ������
	TThostFtdcOrderRefType	ForQuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputForQuoteField;

///ѯ��
typedef struct CThostFtdcForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ѯ������
	TThostFtdcOrderRefType	ForQuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ѯ�۱��
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///ѯ��״̬
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾ѯ�۱��
	TThostFtdcSequenceNoType	BrokerForQutoSeq;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcForQuoteField;

///ѯ�۲�ѯ
typedef struct CThostFtdcQryForQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
} CThostFtdcQryForQuoteField;

///������ѯ����Ϣ
typedef struct CThostFtdcExchangeForQuoteField
{
	///����ѯ�۱��
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///ѯ��״̬
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeForQuoteField;

///������ѯ�۲�ѯ
typedef struct CThostFtdcQryExchangeForQuoteField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeForQuoteField;

///����ı���
typedef struct CThostFtdcInputQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///��������������
	TThostFtdcOrderRefType	AskOrderRef;
	///�����򱨵�����
	TThostFtdcOrderRefType	BidOrderRef;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputQuoteField;

///���뱨�۲���
typedef struct CThostFtdcInputQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���۲�������
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputQuoteActionField;

///����
typedef struct CThostFtdcQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����״̬
	TThostFtdcOrderStatusType	QuoteStatus;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�����������
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///�򷽱������
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾���۱��
	TThostFtdcSequenceNoType	BrokerQuoteSeq;
	///��������������
	TThostFtdcOrderRefType	AskOrderRef;
	///�����򱨵�����
	TThostFtdcOrderRefType	BidOrderRef;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcQuoteField;

///���۲���
typedef struct CThostFtdcQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���۲�������
	TThostFtdcOrderActionRefType	QuoteActionRef;
	///��������
	TThostFtdcOrderRefType	QuoteRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcQuoteActionField;

///���۲�ѯ
typedef struct CThostFtdcQryQuoteField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
} CThostFtdcQryQuoteField;

///������������Ϣ
typedef struct CThostFtdcExchangeQuoteField
{
	///���۸�
	TThostFtdcPriceType	AskPrice;
	///��۸�
	TThostFtdcPriceType	BidPrice;
	///������
	TThostFtdcVolumeType	AskVolume;
	///������
	TThostFtdcVolumeType	BidVolume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///����ƽ��־
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	///��ƽ��־
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	///��Ͷ���ױ���־
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���۱��
	TThostFtdcOrderSysIDType	QuoteSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����״̬
	TThostFtdcOrderStatusType	QuoteStatus;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///�����������
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///�򷽱������
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///Ӧ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeQuoteField;

///���������۲�ѯ
typedef struct CThostFtdcQryExchangeQuoteField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeQuoteField;

///���۲�����ѯ
typedef struct CThostFtdcQryQuoteActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryQuoteActionField;

///���������۲���
typedef struct CThostFtdcExchangeQuoteActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���۲������
	TThostFtdcOrderSysIDType	QuoteSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر��۱��
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeQuoteActionField;

///���������۲�����ѯ
typedef struct CThostFtdcQryExchangeQuoteActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeQuoteActionField;

///��Ȩ��Լdeltaֵ
typedef struct CThostFtdcOptionInstrDeltaField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Deltaֵ
	TThostFtdcRatioType	Delta;
} CThostFtdcOptionInstrDeltaField;

///���������̵�ѯ������
typedef struct CThostFtdcForQuoteRspField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///ѯ�۱��
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///ѯ��ʱ��
	TThostFtdcTimeType	ForQuoteTime;
	///ҵ������
	TThostFtdcDateType	ActionDay;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcForQuoteRspField;

///��ǰ��Ȩ��Լִ��ƫ��ֵ����ϸ����
typedef struct CThostFtdcStrikeOffsetField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ִ��ƫ��ֵ
	TThostFtdcMoneyType	Offset;
	///ִ��ƫ������
	TThostFtdcStrikeOffsetTypeType	OffsetType;
} CThostFtdcStrikeOffsetField;

///��Ȩִ��ƫ��ֵ��ѯ
typedef struct CThostFtdcQryStrikeOffsetField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryStrikeOffsetField;

///����������������
typedef struct CThostFtdcInputBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputBatchOrderActionField;

///������������
typedef struct CThostFtdcBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcBatchOrderActionField;

///������������������
typedef struct CThostFtdcExchangeBatchOrderActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeBatchOrderActionField;

///��ѯ������������
typedef struct CThostFtdcQryBatchOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryBatchOrderActionField;

///�������Ȩ�ԶԳ�
typedef struct CThostFtdcInputOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputOptionSelfCloseField;

///������Ȩ�ԶԳ����
typedef struct CThostFtdcInputOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ȩ�ԶԳ��������
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputOptionSelfCloseActionField;

///��Ȩ�ԶԳ�
typedef struct CThostFtdcOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��Ȩ�ԶԳ��ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///�ԶԳ���
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcOptionSelfCloseField;

///��Ȩ�ԶԳ����
typedef struct CThostFtdcOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Ȩ�ԶԳ��������
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	///��Ȩ�ԶԳ�����
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcOptionSelfCloseActionField;

///��Ȩ�ԶԳ��ѯ
typedef struct CThostFtdcQryOptionSelfCloseField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��ʼʱ��
	TThostFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TThostFtdcTimeType	InsertTimeEnd;
} CThostFtdcQryOptionSelfCloseField;

///��������Ȩ�ԶԳ���Ϣ
typedef struct CThostFtdcExchangeOptionSelfCloseField
{
	///����
	TThostFtdcVolumeType	Volume;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///��Ȩ��Ȩ��ͷ���Ƿ��ԶԳ�
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��Ȩ�ԶԳ��ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///��Ȩ�ԶԳ���
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///��������
	TThostFtdcDateType	InsertDate;
	///����ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///�ԶԳ���
	TThostFtdcExecResultType	ExecResult;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeOptionSelfCloseField;

///��Ȩ�ԶԳ������ѯ
typedef struct CThostFtdcQryOptionSelfCloseActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryOptionSelfCloseActionField;

///��������Ȩ�ԶԳ����
typedef struct CThostFtdcExchangeOptionSelfCloseActionField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ȩ�ԶԳ�������
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///������Ȩ�ԶԳ���
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeOptionSelfCloseActionField;

///��Ϻ�Լ��ȫϵ��
typedef struct CThostFtdcCombInstrumentGuardField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///
	TThostFtdcRatioType	GuarantRatio;
} CThostFtdcCombInstrumentGuardField;

///��Ϻ�Լ��ȫϵ����ѯ
typedef struct CThostFtdcQryCombInstrumentGuardField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryCombInstrumentGuardField;

///������������
typedef struct CThostFtdcInputCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�������
	TThostFtdcOrderRefType	CombActionRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcInputCombActionField;

///�������
typedef struct CThostFtdcCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�������
	TThostFtdcOrderRefType	CombActionRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������ϱ��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���״̬
	TThostFtdcOrderActionStatusType	ActionStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcCombActionField;

///������ϲ�ѯ
typedef struct CThostFtdcQryCombActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryCombActionField;

///���������������Ϣ
typedef struct CThostFtdcExchangeCombActionField
{
	///��������
	TThostFtdcDirectionType	Direction;
	///����
	TThostFtdcVolumeType	Volume;
	///���ָ���
	TThostFtdcCombDirectionType	CombDirection;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������ϱ��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���״̬
	TThostFtdcOrderActionStatusType	ActionStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcExchangeCombActionField;

///������������ϲ�ѯ
typedef struct CThostFtdcQryExchangeCombActionField
{
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryExchangeCombActionField;

///��Ʒ���ۻ���
typedef struct CThostFtdcProductExchRateField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///���۱�������
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	///����
	TThostFtdcExchangeRateType	ExchangeRate;
} CThostFtdcProductExchRateField;

///��Ʒ���ۻ��ʲ�ѯ
typedef struct CThostFtdcQryProductExchRateField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
} CThostFtdcQryProductExchRateField;

///��ѯѯ�ۼ۲����
typedef struct CThostFtdcQryForQuoteParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryForQuoteParamField;

///ѯ�ۼ۲����
typedef struct CThostFtdcForQuoteParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�۲�
	TThostFtdcPriceType	PriceInterval;
} CThostFtdcForQuoteParamField;

///��ǰ��������Ȩ��Լ�����ѵ���ϸ����
typedef struct CThostFtdcMMOptionInstrCommRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TThostFtdcRatioType	StrikeRatioByMoney;
	///ִ��������
	TThostFtdcRatioType	StrikeRatioByVolume;
} CThostFtdcMMOptionInstrCommRateField;

///��������Ȩ�������ʲ�ѯ
typedef struct CThostFtdcQryMMOptionInstrCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryMMOptionInstrCommRateField;

///�����̺�Լ��������
typedef struct CThostFtdcMMInstrumentCommissionRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcRatioType	OpenRatioByMoney;
	///����������
	TThostFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TThostFtdcRatioType	CloseTodayRatioByVolume;
} CThostFtdcMMInstrumentCommissionRateField;

///��ѯ�����̺�Լ��������
typedef struct CThostFtdcQryMMInstrumentCommissionRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryMMInstrumentCommissionRateField;

///��ǰ���������ѵ���ϸ����
typedef struct CThostFtdcInstrumentOrderCommRateField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����������
	TThostFtdcRatioType	OrderCommByVolume;
	///����������
	TThostFtdcRatioType	OrderActionCommByVolume;
} CThostFtdcInstrumentOrderCommRateField;

///�����������ʲ�ѯ
typedef struct CThostFtdcQryInstrumentOrderCommRateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryInstrumentOrderCommRateField;

///�г�����
typedef struct CThostFtdcMarketDataField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
	///������
	TThostFtdcPriceType	ClosePrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///ҵ������
	TThostFtdcDateType	ActionDay;
} CThostFtdcMarketDataField;

///�����������
typedef struct CThostFtdcMarketDataBaseField
{
	///������
	TThostFtdcDateType	TradingDay;
	///�ϴν����
	TThostFtdcPriceType	PreSettlementPrice;
	///������
	TThostFtdcPriceType	PreClosePrice;
	///��ֲ���
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TThostFtdcRatioType	PreDelta;
} CThostFtdcMarketDataBaseField;

///���龲̬����
typedef struct CThostFtdcMarketDataStaticField
{
	///����
	TThostFtdcPriceType	OpenPrice;
	///��߼�
	TThostFtdcPriceType	HighestPrice;
	///��ͼ�
	TThostFtdcPriceType	LowestPrice;
	///������
	TThostFtdcPriceType	ClosePrice;
	///��ͣ���
	TThostFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TThostFtdcPriceType	LowerLimitPrice;
	///���ν����
	TThostFtdcPriceType	SettlementPrice;
	///����ʵ��
	TThostFtdcRatioType	CurrDelta;
} CThostFtdcMarketDataStaticField;

///�������³ɽ�����
typedef struct CThostFtdcMarketDataLastMatchField
{
	///���¼�
	TThostFtdcPriceType	LastPrice;
	///����
	TThostFtdcVolumeType	Volume;
	///�ɽ����
	TThostFtdcMoneyType	Turnover;
	///�ֲ���
	TThostFtdcLargeVolumeType	OpenInterest;
} CThostFtdcMarketDataLastMatchField;

///�������ż�����
typedef struct CThostFtdcMarketDataBestPriceField
{
	///�����һ
	TThostFtdcPriceType	BidPrice1;
	///������һ
	TThostFtdcVolumeType	BidVolume1;
	///������һ
	TThostFtdcPriceType	AskPrice1;
	///������һ
	TThostFtdcVolumeType	AskVolume1;
} CThostFtdcMarketDataBestPriceField;

///�����������������
typedef struct CThostFtdcMarketDataBid23Field
{
	///����۶�
	TThostFtdcPriceType	BidPrice2;
	///��������
	TThostFtdcVolumeType	BidVolume2;
	///�������
	TThostFtdcPriceType	BidPrice3;
	///��������
	TThostFtdcVolumeType	BidVolume3;
} CThostFtdcMarketDataBid23Field;

///������������������
typedef struct CThostFtdcMarketDataAsk23Field
{
	///�����۶�
	TThostFtdcPriceType	AskPrice2;
	///��������
	TThostFtdcVolumeType	AskVolume2;
	///��������
	TThostFtdcPriceType	AskPrice3;
	///��������
	TThostFtdcVolumeType	AskVolume3;
} CThostFtdcMarketDataAsk23Field;

///���������ġ�������
typedef struct CThostFtdcMarketDataBid45Field
{
	///�������
	TThostFtdcPriceType	BidPrice4;
	///��������
	TThostFtdcVolumeType	BidVolume4;
	///�������
	TThostFtdcPriceType	BidPrice5;
	///��������
	TThostFtdcVolumeType	BidVolume5;
} CThostFtdcMarketDataBid45Field;

///���������ġ�������
typedef struct CThostFtdcMarketDataAsk45Field
{
	///��������
	TThostFtdcPriceType	AskPrice4;
	///��������
	TThostFtdcVolumeType	AskVolume4;
	///��������
	TThostFtdcPriceType	AskPrice5;
	///��������
	TThostFtdcVolumeType	AskVolume5;
} CThostFtdcMarketDataAsk45Field;

///�������ʱ������
typedef struct CThostFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TThostFtdcMillisecType	UpdateMillisec;
	///ҵ������
	TThostFtdcDateType	ActionDay;
} CThostFtdcMarketDataUpdateTimeField;

///���齻������������
typedef struct CThostFtdcMarketDataExchangeField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcMarketDataExchangeField;

///ָ���ĺ�Լ
typedef struct CThostFtdcSpecificInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcSpecificInstrumentField;

///��Լ״̬
typedef struct CThostFtdcInstrumentStatusField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///���������
	TThostFtdcSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TThostFtdcInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TThostFtdcTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TThostFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TThostFtdcInstStatusEnterReasonType	EnterReason;
} CThostFtdcInstrumentStatusField;

///��ѯ��Լ״̬
typedef struct CThostFtdcQryInstrumentStatusField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
} CThostFtdcQryInstrumentStatusField;

///Ͷ�����˻�
typedef struct CThostFtdcInvestorAccountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcInvestorAccountField;

///����ӯ���㷨
typedef struct CThostFtdcPositionProfitAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///ӯ���㷨
	TThostFtdcAlgorithmType	Algorithm;
	///��ע
	TThostFtdcMemoType	Memo;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcPositionProfitAlgorithmField;

///��Ա�ʽ��ۿ�
typedef struct CThostFtdcDiscountField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ʽ��ۿ۱���
	TThostFtdcRatioType	Discount;
} CThostFtdcDiscountField;

///��ѯת������
typedef struct CThostFtdcQryTransferBankField
{
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
} CThostFtdcQryTransferBankField;

///ת������
typedef struct CThostFtdcTransferBankField
{
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///��������
	TThostFtdcBankNameType	BankName;
	///�Ƿ��Ծ
	TThostFtdcBoolType	IsActive;
} CThostFtdcTransferBankField;

///��ѯͶ���ֲ߳���ϸ
typedef struct CThostFtdcQryInvestorPositionDetailField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryInvestorPositionDetailField;

///Ͷ���ֲ߳���ϸ
typedef struct CThostFtdcInvestorPositionDetailField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///��������
	TThostFtdcDateType	OpenDate;
	///�ɽ����
	TThostFtdcTradeIDType	TradeID;
	///����
	TThostFtdcVolumeType	Volume;
	///���ּ�
	TThostFtdcPriceType	OpenPrice;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�ɽ�����
	TThostFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���ն���ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///������
	TThostFtdcPriceType	LastSettlementPrice;
	///�����
	TThostFtdcPriceType	SettlementPrice;
	///ƽ����
	TThostFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TThostFtdcMoneyType	CloseAmount;
} CThostFtdcInvestorPositionDetailField;

///�ʽ��˻�������
typedef struct CThostFtdcTradingAccountPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcTradingAccountPasswordField;

///���������鱨�̻�
typedef struct CThostFtdcMDTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TThostFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TThostFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TThostFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TThostFtdcTimeType	LastReportTime;
	///�����������
	TThostFtdcDateType	ConnectDate;
	///�������ʱ��
	TThostFtdcTimeType	ConnectTime;
	///��������
	TThostFtdcDateType	StartDate;
	///����ʱ��
	TThostFtdcTimeType	StartTime;
	///������
	TThostFtdcDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TThostFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
} CThostFtdcMDTraderOfferField;

///��ѯ���鱨�̻�
typedef struct CThostFtdcQryMDTraderOfferField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
} CThostFtdcQryMDTraderOfferField;

///��ѯ�ͻ�֪ͨ
typedef struct CThostFtdcQryNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcQryNoticeField;

///�ͻ�֪ͨ
typedef struct CThostFtdcNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ϣ����
	TThostFtdcContentType	Content;
	///���͹�˾֪ͨ�������к�
	TThostFtdcSequenceLabelType	SequenceLabel;
} CThostFtdcNoticeField;

///�û�Ȩ��
typedef struct CThostFtdcUserRightField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ͻ�Ȩ������
	TThostFtdcUserRightTypeType	UserRightType;
	///�Ƿ��ֹ
	TThostFtdcBoolType	IsForbidden;
} CThostFtdcUserRightField;

///��ѯ������Ϣȷ����
typedef struct CThostFtdcQrySettlementInfoConfirmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQrySettlementInfoConfirmField;

///װ�ؽ�����Ϣ
typedef struct CThostFtdcLoadSettlementInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcLoadSettlementInfoField;

///���͹�˾�����ʽ��㷨��
typedef struct CThostFtdcBrokerWithdrawAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�����ʽ��㷨
	TThostFtdcAlgorithmType	WithdrawAlgorithm;
	///�ʽ�ʹ����
	TThostFtdcRatioType	UsingRatio;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	IncludeCloseProfit;
	///�����޲����޳ɽ��ͻ��Ƿ��ܿ����������
	TThostFtdcAllWithoutTradeType	AllWithoutTrade;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///�Ƿ������û��¼�
	TThostFtdcBoolType	IsBrokerUserEvent;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������Ѻ����
	TThostFtdcRatioType	FundMortgageRatio;
	///Ȩ���㷨
	TThostFtdcBalanceAlgorithmType	BalanceAlgorithm;
} CThostFtdcBrokerWithdrawAlgorithmField;

///�ʽ��˻���������
typedef struct CThostFtdcTradingAccountPasswordUpdateV1Field
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
} CThostFtdcTradingAccountPasswordUpdateV1Field;

///�ʽ��˻���������
typedef struct CThostFtdcTradingAccountPasswordUpdateField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///ԭ���Ŀ���
	TThostFtdcPasswordType	OldPassword;
	///�µĿ���
	TThostFtdcPasswordType	NewPassword;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcTradingAccountPasswordUpdateField;

///��ѯ��Ϻ�Լ����
typedef struct CThostFtdcQryCombinationLegField
{
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TThostFtdcInstrumentIDType	LegInstrumentID;
} CThostFtdcQryCombinationLegField;

///��ѯ��Ϻ�Լ����
typedef struct CThostFtdcQrySyncStatusField
{
	///������
	TThostFtdcDateType	TradingDay;
} CThostFtdcQrySyncStatusField;

///��Ͻ��׺�Լ�ĵ���
typedef struct CThostFtdcCombinationLegField
{
	///��Ϻ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TThostFtdcInstrumentIDType	LegInstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///��������
	TThostFtdcImplyLevelType	ImplyLevel;
} CThostFtdcCombinationLegField;

///����ͬ��״̬
typedef struct CThostFtdcSyncStatusField
{
	///������
	TThostFtdcDateType	TradingDay;
	///����ͬ��״̬
	TThostFtdcDataSyncStatusType	DataSyncStatus;
} CThostFtdcSyncStatusField;

///��ѯ��ϵ��
typedef struct CThostFtdcQryLinkManField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryLinkManField;

///��ϵ��
typedef struct CThostFtdcLinkManField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϵ������
	TThostFtdcPersonTypeType	PersonType;
	///֤������
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///����
	TThostFtdcPartyNameType	PersonName;
	///��ϵ�绰
	TThostFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TThostFtdcAddressType	Address;
	///��������
	TThostFtdcZipCodeType	ZipCode;
	///���ȼ�
	TThostFtdcPriorityType	Priority;
	///������������
	TThostFtdcUOAZipCodeType	UOAZipCode;
	///ȫ��
	TThostFtdcInvestorFullNameType	PersonFullName;
} CThostFtdcLinkManField;

///��ѯ���͹�˾�û��¼�
typedef struct CThostFtdcQryBrokerUserEventField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��¼�����
	TThostFtdcUserEventTypeType	UserEventType;
} CThostFtdcQryBrokerUserEventField;

///��ѯ���͹�˾�û��¼�
typedef struct CThostFtdcBrokerUserEventField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û��¼�����
	TThostFtdcUserEventTypeType	UserEventType;
	///�û��¼����
	TThostFtdcSequenceNoType	EventSequenceNo;
	///�¼���������
	TThostFtdcDateType	EventDate;
	///�¼�����ʱ��
	TThostFtdcTimeType	EventTime;
	///�û��¼���Ϣ
	TThostFtdcUserEventInfoType	UserEventInfo;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcBrokerUserEventField;

///��ѯǩԼ��������
typedef struct CThostFtdcQryContractBankField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
} CThostFtdcQryContractBankField;

///��ѯǩԼ������Ӧ
typedef struct CThostFtdcContractBankField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з����Ĵ���
	TThostFtdcBankBrchIDType	BankBrchID;
	///��������
	TThostFtdcBankNameType	BankName;
} CThostFtdcContractBankField;

///Ͷ������ϳֲ���ϸ
typedef struct CThostFtdcInvestorPositionCombineDetailField
{
	///������
	TThostFtdcDateType	TradingDay;
	///��������
	TThostFtdcDateType	OpenDate;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϱ��
	TThostFtdcTradeIDType	ComTradeID;
	///��ϱ��
	TThostFtdcTradeIDType	TradeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcDirectionType	Direction;
	///�ֲ���
	TThostFtdcVolumeType	TotalAmt;
	///Ͷ���߱�֤��
	TThostFtdcMoneyType	Margin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��֤����
	TThostFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TThostFtdcRatioType	MarginRateByVolume;
	///���ȱ��
	TThostFtdcLegIDType	LegID;
	///���ȳ���
	TThostFtdcLegMultipleType	LegMultiple;
	///��ϳֲֺ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///�ɽ����
	TThostFtdcTradeGroupIDType	TradeGroupID;
} CThostFtdcInvestorPositionCombineDetailField;

///Ԥ��
typedef struct CThostFtdcParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TThostFtdcBoolType	UserForceClose;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ԥ�񱨵����
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///Ԥ��״̬
	TThostFtdcParkedOrderStatusType	Status;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcParkedOrderField;

///����Ԥ�񵥲���
typedef struct CThostFtdcParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ԥ�񳷵������
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	///�û�����
	TThostFtdcUserTypeType	UserType;
	///Ԥ�񳷵�״̬
	TThostFtdcParkedOrderStatusType	Status;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcParkedOrderActionField;

///��ѯԤ��
typedef struct CThostFtdcQryParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryParkedOrderField;

///��ѯԤ�񳷵�
typedef struct CThostFtdcQryParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryParkedOrderActionField;

///ɾ��Ԥ��
typedef struct CThostFtdcRemoveParkedOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ԥ�񱨵����
	TThostFtdcParkedOrderIDType	ParkedOrderID;
} CThostFtdcRemoveParkedOrderField;

///ɾ��Ԥ�񳷵�
typedef struct CThostFtdcRemoveParkedOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ԥ�񳷵����
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
} CThostFtdcRemoveParkedOrderActionField;

///���͹�˾�����ʽ��㷨��
typedef struct CThostFtdcInvestorWithdrawAlgorithmField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����ʽ����
	TThostFtdcRatioType	UsingRatio;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������Ѻ����
	TThostFtdcRatioType	FundMortgageRatio;
} CThostFtdcInvestorWithdrawAlgorithmField;

///��ѯ��ϳֲ���ϸ
typedef struct CThostFtdcQryInvestorPositionCombineDetailField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��ϳֲֺ�Լ����
	TThostFtdcInstrumentIDType	CombInstrumentID;
} CThostFtdcQryInvestorPositionCombineDetailField;

///�ɽ�����
typedef struct CThostFtdcMarketDataAveragePriceField
{
	///���վ���
	TThostFtdcPriceType	AveragePrice;
} CThostFtdcMarketDataAveragePriceField;

///У��Ͷ��������
typedef struct CThostFtdcVerifyInvestorPasswordField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����
	TThostFtdcPasswordType	Password;
} CThostFtdcVerifyInvestorPasswordField;

///�û�IP
typedef struct CThostFtdcUserIPField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///IP��ַ����
	TThostFtdcIPAddressType	IPMask;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcUserIPField;

///�û��¼�֪ͨ��Ϣ
typedef struct CThostFtdcTradingNoticeInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///��Ϣ����
	TThostFtdcContentType	FieldContent;
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
} CThostFtdcTradingNoticeInfoField;

///�û��¼�֪ͨ
typedef struct CThostFtdcTradingNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TThostFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����ϵ�к�
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TThostFtdcContentType	FieldContent;
} CThostFtdcTradingNoticeField;

///��ѯ�����¼�֪ͨ
typedef struct CThostFtdcQryTradingNoticeField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryTradingNoticeField;

///��ѯ���󱨵�
typedef struct CThostFtdcQryErrOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryErrOrderField;

///���󱨵�
typedef struct CThostFtdcErrOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TThostFtdcBoolType	UserForceClose;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���ױ���
	TThostFtdcClientIDType	ClientID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcErrOrderField;

///��ѯ���󱨵�����
typedef struct CThostFtdcErrorConditionalOrderField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�����۸�����
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TThostFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///����
	TThostFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TThostFtdcTimeConditionType	TimeCondition;
	///GTD����
	TThostFtdcDateType	GTDDate;
	///�ɽ�������
	TThostFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TThostFtdcVolumeType	MinVolume;
	///��������
	TThostFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TThostFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TThostFtdcSequenceNoType	NotifySequence;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TThostFtdcOrderSourceType	OrderSource;
	///����״̬
	TThostFtdcOrderStatusType	OrderStatus;
	///��������
	TThostFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TThostFtdcVolumeType	VolumeTraded;
	///ʣ������
	TThostFtdcVolumeType	VolumeTotal;
	///��������
	TThostFtdcDateType	InsertDate;
	///ί��ʱ��
	TThostFtdcTimeType	InsertTime;
	///����ʱ��
	TThostFtdcTimeType	ActiveTime;
	///����ʱ��
	TThostFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TThostFtdcTimeType	UpdateTime;
	///����ʱ��
	TThostFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TThostFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TThostFtdcParticipantIDType	ClearingPartID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TThostFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///�û�ǿ����־
	TThostFtdcBoolType	UserForceClose;
	///�����û�����
	TThostFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///֣�����ɽ�����
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��������־
	TThostFtdcBoolType	IsSwapOrder;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///�ʽ��˺�
	TThostFtdcAccountIDType	AccountID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
} CThostFtdcErrorConditionalOrderField;

///��ѯ���󱨵�����
typedef struct CThostFtdcQryErrOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryErrOrderActionField;

///���󱨵�����
typedef struct CThostFtdcErrOrderActionField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������������
	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	TThostFtdcOrderRefType	OrderRef;
	///������
	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TThostFtdcFrontIDType	FrontID;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�������
	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	TThostFtdcActionFlagType	ActionFlag;
	///�۸�
	TThostFtdcPriceType	LimitPrice;
	///�����仯
	TThostFtdcVolumeType	VolumeChange;
	///��������
	TThostFtdcDateType	ActionDate;
	///����ʱ��
	TThostFtdcTimeType	ActionTime;
	///����������Ա����
	TThostFtdcTraderIDType	TraderID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///���ر������
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TThostFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TThostFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///״̬��Ϣ
	TThostFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///Ӫҵ�����
	TThostFtdcBranchIDType	BranchID;
	///Ͷ�ʵ�Ԫ����
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TThostFtdcMacAddressType	MacAddress;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcErrOrderActionField;

///��ѯ������״̬
typedef struct CThostFtdcQryExchangeSequenceField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryExchangeSequenceField;

///������״̬
typedef struct CThostFtdcExchangeSequenceField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///���
	TThostFtdcSequenceNoType	SequenceNo;
	///��Լ����״̬
	TThostFtdcInstrumentStatusType	MarketStatus;
} CThostFtdcExchangeSequenceField;

///���ݼ۸��ѯ��󱨵�����
typedef struct CThostFtdcQueryMaxOrderVolumeWithPriceField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///��ƽ��־
	TThostFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///�������������
	TThostFtdcVolumeType	MaxVolume;
	///�����۸�
	TThostFtdcPriceType	Price;
} CThostFtdcQueryMaxOrderVolumeWithPriceField;

///��ѯ���͹�˾���ײ���
typedef struct CThostFtdcQryBrokerTradingParamsField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcQryBrokerTradingParamsField;

///���͹�˾���ײ���
typedef struct CThostFtdcBrokerTradingParamsField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///��֤��۸�����
	TThostFtdcMarginPriceTypeType	MarginPriceType;
	///ӯ���㷨
	TThostFtdcAlgorithmType	Algorithm;
	///�����Ƿ����ƽ��ӯ��
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///��ȨȨ����۸�����
	TThostFtdcOptionRoyaltyPriceTypeType	OptionRoyaltyPriceType;
} CThostFtdcBrokerTradingParamsField;

///��ѯ���͹�˾�����㷨
typedef struct CThostFtdcQryBrokerTradingAlgosField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryBrokerTradingAlgosField;

///���͹�˾�����㷨
typedef struct CThostFtdcBrokerTradingAlgosField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///�ֲִ����㷨���
	TThostFtdcHandlePositionAlgoIDType	HandlePositionAlgoID;
	///Ѱ�ұ�֤�����㷨���
	TThostFtdcFindMarginRateAlgoIDType	FindMarginRateAlgoID;
	///�ʽ����㷨���
	TThostFtdcHandleTradingAccountAlgoIDType	HandleTradingAccountAlgoID;
} CThostFtdcBrokerTradingAlgosField;

///��ѯ���͹�˾�ʽ�
typedef struct CThostFtdcQueryBrokerDepositField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQueryBrokerDepositField;

///���͹�˾�ʽ�
typedef struct CThostFtdcBrokerDepositField
{
	///��������
	TThostFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��Ա����
	TThostFtdcParticipantIDType	ParticipantID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///�ϴν���׼����
	TThostFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TThostFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�ڻ�����׼����
	TThostFtdcMoneyType	Balance;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcMoneyType	Withdraw;
	///�����ʽ�
	TThostFtdcMoneyType	Available;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
} CThostFtdcBrokerDepositField;

///��ѯ��֤����ϵͳ���͹�˾��Կ
typedef struct CThostFtdcQryCFMMCBrokerKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
} CThostFtdcQryCFMMCBrokerKeyField;

///��֤����ϵͳ���͹�˾��Կ
typedef struct CThostFtdcCFMMCBrokerKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///��Կ��������
	TThostFtdcDateType	CreateDate;
	///��Կ����ʱ��
	TThostFtdcTimeType	CreateTime;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TThostFtdcCFMMCKeyType	CurrentKey;
	///��̬��Կ����
	TThostFtdcCFMMCKeyKindType	KeyKind;
} CThostFtdcCFMMCBrokerKeyField;

///��֤����ϵͳ���͹�˾�ʽ��˻���Կ
typedef struct CThostFtdcCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TThostFtdcCFMMCKeyType	CurrentKey;
} CThostFtdcCFMMCTradingAccountKeyField;

///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
typedef struct CThostFtdcQryCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQryCFMMCTradingAccountKeyField;

///�û���̬���Ʋ���
typedef struct CThostFtdcBrokerUserOTPParamField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��̬�����ṩ��
	TThostFtdcOTPVendorsIDType	OTPVendorsID;
	///��̬�������к�
	TThostFtdcSerialNumberType	SerialNumber;
	///������Կ
	TThostFtdcAuthKeyType	AuthKey;
	///Ư��ֵ
	TThostFtdcLastDriftType	LastDrift;
	///�ɹ�ֵ
	TThostFtdcLastSuccessType	LastSuccess;
	///��̬��������
	TThostFtdcOTPTypeType	OTPType;
} CThostFtdcBrokerUserOTPParamField;

///�ֹ�ͬ���û���̬����
typedef struct CThostFtdcManualSyncBrokerUserOTPField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��̬��������
	TThostFtdcOTPTypeType	OTPType;
	///��һ����̬����
	TThostFtdcPasswordType	FirstOTP;
	///�ڶ�����̬����
	TThostFtdcPasswordType	SecondOTP;
} CThostFtdcManualSyncBrokerUserOTPField;

///Ͷ������������ģ��
typedef struct CThostFtdcCommRateModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
	///ģ������
	TThostFtdcCommModelNameType	CommModelName;
} CThostFtdcCommRateModelField;

///�����ѯͶ������������ģ��
typedef struct CThostFtdcQryCommRateModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TThostFtdcInvestorIDType	CommModelID;
} CThostFtdcQryCommRateModelField;

///Ͷ���߱�֤����ģ��
typedef struct CThostFtdcMarginModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
	///ģ������
	TThostFtdcCommModelNameType	MarginModelName;
} CThostFtdcMarginModelField;

///�����ѯͶ���߱�֤����ģ��
typedef struct CThostFtdcQryMarginModelField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///��֤����ģ�����
	TThostFtdcInvestorIDType	MarginModelID;
} CThostFtdcQryMarginModelField;

///�ֵ��۵���Ϣ
typedef struct CThostFtdcEWarrantOffsetField
{
	///��������
	TThostFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///��������
	TThostFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
	///����
	TThostFtdcVolumeType	Volume;
} CThostFtdcEWarrantOffsetField;

///��ѯ�ֵ��۵���Ϣ
typedef struct CThostFtdcQryEWarrantOffsetField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
} CThostFtdcQryEWarrantOffsetField;

///��ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
typedef struct CThostFtdcQryInvestorProductGroupMarginField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///Ʒ��/��Ʒ�ֱ�ʾ
	TThostFtdcInstrumentIDType	ProductGroupID;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
} CThostFtdcQryInvestorProductGroupMarginField;

///Ͷ����Ʒ��/��Ʒ�ֱ�֤��
typedef struct CThostFtdcInvestorProductGroupMarginField
{
	///Ʒ��/��Ʒ�ֱ�ʾ
	TThostFtdcInstrumentIDType	ProductGroupID;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcSettlementIDType	SettlementID;
	///����ı�֤��
	TThostFtdcMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	TThostFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TThostFtdcMoneyType	ShortFrozenMargin;
	///ռ�õı�֤��
	TThostFtdcMoneyType	UseMargin;
	///��ͷ��֤��
	TThostFtdcMoneyType	LongUseMargin;
	///��ͷ��֤��
	TThostFtdcMoneyType	ShortUseMargin;
	///��������֤��
	TThostFtdcMoneyType	ExchMargin;
	///��������ͷ��֤��
	TThostFtdcMoneyType	LongExchMargin;
	///��������ͷ��֤��
	TThostFtdcMoneyType	ShortExchMargin;
	///ƽ��ӯ��
	TThostFtdcMoneyType	CloseProfit;
	///�����������
	TThostFtdcMoneyType	FrozenCommission;
	///������
	TThostFtdcMoneyType	Commission;
	///������ʽ�
	TThostFtdcMoneyType	FrozenCash;
	///�ʽ���
	TThostFtdcMoneyType	CashIn;
	///�ֲ�ӯ��
	TThostFtdcMoneyType	PositionProfit;
	///�۵��ܽ��
	TThostFtdcMoneyType	OffsetAmount;
	///��ͷ�۵��ܽ��
	TThostFtdcMoneyType	LongOffsetAmount;
	///��ͷ�۵��ܽ��
	TThostFtdcMoneyType	ShortOffsetAmount;
	///�������۵��ܽ��
	TThostFtdcMoneyType	ExchOffsetAmount;
	///��������ͷ�۵��ܽ��
	TThostFtdcMoneyType	LongExchOffsetAmount;
	///��������ͷ�۵��ܽ��
	TThostFtdcMoneyType	ShortExchOffsetAmount;
	///Ͷ���ױ���־
	TThostFtdcHedgeFlagType	HedgeFlag;
} CThostFtdcInvestorProductGroupMarginField;

///��ѯ��������û�����
typedef struct CThostFtdcQueryCFMMCTradingAccountTokenField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
} CThostFtdcQueryCFMMCTradingAccountTokenField;

///��������û�����
typedef struct CThostFtdcCFMMCTradingAccountTokenField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TThostFtdcParticipantIDType	ParticipantID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///��Կ���
	TThostFtdcSequenceNoType	KeyID;
	///��̬����
	TThostFtdcCFMMCTokenType	Token;
} CThostFtdcCFMMCTradingAccountTokenField;

///��ѯ��Ʒ��
typedef struct CThostFtdcQryProductGroupField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
} CThostFtdcQryProductGroupField;

///Ͷ����Ʒ��/��Ʒ�ֱ�֤���Ʒ��
typedef struct CThostFtdcProductGroupField
{
	///��Ʒ����
	TThostFtdcInstrumentIDType	ProductID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///��Ʒ�����
	TThostFtdcInstrumentIDType	ProductGroupID;
} CThostFtdcProductGroupField;

///����������
typedef struct CThostFtdcBulletinField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcDateType	TradingDay;
	///������
	TThostFtdcBulletinIDType	BulletinID;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��������
	TThostFtdcNewsTypeType	NewsType;
	///�����̶�
	TThostFtdcNewsUrgencyType	NewsUrgency;
	///����ʱ��
	TThostFtdcTimeType	SendTime;
	///��ϢժҪ
	TThostFtdcAbstractType	Abstract;
	///��Ϣ��Դ
	TThostFtdcComeFromType	ComeFrom;
	///��Ϣ����
	TThostFtdcContentType	Content;
	///WEB��ַ
	TThostFtdcURLLinkType	URLLink;
	///�г�����
	TThostFtdcMarketIDType	MarketID;
} CThostFtdcBulletinField;

///��ѯ����������
typedef struct CThostFtdcQryBulletinField
{
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///������
	TThostFtdcBulletinIDType	BulletinID;
	///���к�
	TThostFtdcSequenceNoType	SequenceNo;
	///��������
	TThostFtdcNewsTypeType	NewsType;
	///�����̶�
	TThostFtdcNewsUrgencyType	NewsUrgency;
} CThostFtdcQryBulletinField;

///ת�ʿ�������
typedef struct CThostFtdcReqOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
} CThostFtdcReqOpenAccountField;

///ת����������
typedef struct CThostFtdcReqCancelAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
} CThostFtdcReqCancelAccountField;

///��������˻�����
typedef struct CThostFtdcReqChangeAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TThostFtdcBankAccountType	NewBankAccount;
	///����������
	TThostFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TThostFtdcTIDType	TID;
	///ժҪ
	TThostFtdcDigestType	Digest;
} CThostFtdcReqChangeAccountField;

///ת������
typedef struct CThostFtdcReqTransferField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
} CThostFtdcReqTransferField;

///���з��������ʽ�ת�ڻ���Ӧ
typedef struct CThostFtdcRspTransferField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcRspTransferField;

///��������
typedef struct CThostFtdcReqRepealField
{
	///����ʱ����
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TThostFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TThostFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
} CThostFtdcReqRepealField;

///������Ӧ
typedef struct CThostFtdcRspRepealField
{
	///����ʱ����
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TThostFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TThostFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TThostFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TThostFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TThostFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TThostFtdcAddInfoType	Message;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///ת�˽���״̬
	TThostFtdcTransferStatusType	TransferStatus;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcRspRepealField;

///��ѯ�˻���Ϣ����
typedef struct CThostFtdcReqQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
} CThostFtdcReqQueryAccountField;

///��ѯ�˻���Ϣ��Ӧ
typedef struct CThostFtdcRspQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
} CThostFtdcRspQueryAccountField;

///����ǩ��ǩ��
typedef struct CThostFtdcFutureSignIOField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
} CThostFtdcFutureSignIOField;

///����ǩ����Ӧ
typedef struct CThostFtdcRspFutureSignInField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TThostFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TThostFtdcPasswordKeyType	MacKey;
} CThostFtdcRspFutureSignInField;

///����ǩ������
typedef struct CThostFtdcReqFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
} CThostFtdcReqFutureSignOutField;

///����ǩ����Ӧ
typedef struct CThostFtdcRspFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcRspFutureSignOutField;

///��ѯָ����ˮ�ŵĽ��׽������
typedef struct CThostFtdcReqQueryTradeResultBySerialField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��ˮ��
	TThostFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TThostFtdcOrganCodeType	RefrenceIssure;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TThostFtdcDigestType	Digest;
} CThostFtdcReqQueryTradeResultBySerialField;

///��ѯָ����ˮ�ŵĽ��׽����Ӧ
typedef struct CThostFtdcRspQueryTradeResultBySerialField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///��ˮ��
	TThostFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TThostFtdcOrganCodeType	RefrenceIssure;
	///ԭʼ���ش���
	TThostFtdcReturnCodeType	OriginReturnCode;
	///ԭʼ����������
	TThostFtdcDescrInfoForReturnCodeType	OriginDescrInfoForReturnCode;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TThostFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TThostFtdcDigestType	Digest;
} CThostFtdcRspQueryTradeResultBySerialField;

///�����ļ���������
typedef struct CThostFtdcReqDayEndFileReadyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ļ�ҵ����
	TThostFtdcFileBusinessCodeType	FileBusinessCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
} CThostFtdcReqDayEndFileReadyField;

///���ؽ��
typedef struct CThostFtdcReturnResultField
{
	///���ش���
	TThostFtdcReturnCodeType	ReturnCode;
	///����������
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
} CThostFtdcReturnResultField;

///��֤�ڻ��ʽ�����
typedef struct CThostFtdcVerifyFuturePasswordField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///����ID
	TThostFtdcTIDType	TID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcVerifyFuturePasswordField;

///��֤�ͻ���Ϣ
typedef struct CThostFtdcVerifyCustInfoField
{
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
} CThostFtdcVerifyCustInfoField;

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
typedef struct CThostFtdcVerifyFuturePasswordAndCustInfoField
{
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcVerifyFuturePasswordAndCustInfoField;

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
typedef struct CThostFtdcDepositResultInformField
{
	///�������ˮ�ţ�����ˮ��Ϊ���ڱ��̷��ص���ˮ��
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�����
	TThostFtdcMoneyType	Deposit;
	///������
	TThostFtdcRequestIDType	RequestID;
	///���ش���
	TThostFtdcReturnCodeType	ReturnCode;
	///����������
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
} CThostFtdcDepositResultInformField;

///���׺��������ڱ��̷�����Կͬ������
typedef struct CThostFtdcReqSyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
} CThostFtdcReqSyncKeyField;

///���׺��������ڱ��̷�����Կͬ����Ӧ
typedef struct CThostFtdcRspSyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcRspSyncKeyField;

///��ѯ�˻���Ϣ֪ͨ
typedef struct CThostFtdcNotifyQueryAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///���п��ý��
	TThostFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TThostFtdcTradeAmountType	BankFetchAmount;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcNotifyQueryAccountField;

///����ת�˽�����ˮ��
typedef struct CThostFtdcTransferSerialField
{
	///ƽ̨��ˮ��
	TThostFtdcPlateSerialType	PlateSerial;
	///���׷�������
	TThostFtdcTradeDateType	TradeDate;
	///��������
	TThostFtdcDateType	TradingDay;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///���״���
	TThostFtdcTradeCodeType	TradeCode;
	///�Ự���
	TThostFtdcSessionIDType	SessionID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///�ڻ���˾����
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///�ڻ���˾�ʺ�����
	TThostFtdcFutureAccTypeType	FutureAccType;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///Ͷ���ߴ���
	TThostFtdcInvestorIDType	InvestorID;
	///�ڻ���˾��ˮ��
	TThostFtdcFutureSerialType	FutureSerial;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���׽��
	TThostFtdcTradeAmountType	TradeAmount;
	///Ӧ�տͻ�����
	TThostFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TThostFtdcFutureFeeType	BrokerFee;
	///��Ч��־
	TThostFtdcAvailabilityFlagType	AvailabilityFlag;
	///����Ա
	TThostFtdcOperatorCodeType	OperatorCode;
	///�������ʺ�
	TThostFtdcBankAccountType	BankNewAccount;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcTransferSerialField;

///�����ѯת����ˮ
typedef struct CThostFtdcQryTransferSerialField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcQryTransferSerialField;

///����ǩ��֪ͨ
typedef struct CThostFtdcNotifyFutureSignInField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TThostFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TThostFtdcPasswordKeyType	MacKey;
} CThostFtdcNotifyFutureSignInField;

///����ǩ��֪ͨ
typedef struct CThostFtdcNotifyFutureSignOutField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcNotifyFutureSignOutField;

///���׺��������ڱ��̷�����Կͬ����������֪ͨ
typedef struct CThostFtdcNotifySyncKeyField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TThostFtdcAddInfoType	Message;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///������
	TThostFtdcRequestIDType	RequestID;
	///����ID
	TThostFtdcTIDType	TID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcNotifySyncKeyField;

///�����ѯ����ǩԼ��ϵ
typedef struct CThostFtdcQryAccountregisterField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcQryAccountregisterField;

///�ͻ���������Ϣ��
typedef struct CThostFtdcAccountregisterField
{
	///��������
	TThostFtdcTradeDateType	TradeDay;
	///���б���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///�ڻ���˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�ڻ���˾��֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///���������
	TThostFtdcOpenOrDestroyType	OpenOrDestroy;
	///ǩԼ����
	TThostFtdcTradeDateType	RegDate;
	///��Լ����
	TThostFtdcTradeDateType	OutDate;
	///����ID
	TThostFtdcTIDType	TID;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
} CThostFtdcAccountregisterField;

///���ڿ�����Ϣ
typedef struct CThostFtdcOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcOpenAccountField;

///����������Ϣ
typedef struct CThostFtdcCancelAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///������־
	TThostFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TThostFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TThostFtdcBankAccountType	BankSecuAcc;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TThostFtdcOperNoType	OperNo;
	///����ID
	TThostFtdcTIDType	TID;
	///�û���ʶ
	TThostFtdcUserIDType	UserID;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcCancelAccountField;

///���ڱ�������˺���Ϣ
typedef struct CThostFtdcChangeAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TThostFtdcBankAccountType	NewBankAccount;
	///����������
	TThostFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TThostFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TThostFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TThostFtdcTIDType	TID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcChangeAccountField;

///�����������Ա����Ȩ��
typedef struct CThostFtdcSecAgentACIDMapField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ʽ��˻�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcCurrencyIDType	CurrencyID;
	///�����н�����ʽ��ʺ�
	TThostFtdcAccountIDType	BrokerSecAgentID;
} CThostFtdcSecAgentACIDMapField;

///�����������Ա����Ȩ�޲�ѯ
typedef struct CThostFtdcQrySecAgentACIDMapField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�ʽ��˻�
	TThostFtdcAccountIDType	AccountID;
	///����
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcQrySecAgentACIDMapField;

///�ֱ����Ľ���Ȩ��
typedef struct CThostFtdcUserRightsAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
} CThostFtdcUserRightsAssignField;

///���ù�˾�Ƿ����ڱ���ʾ�Ľ���Ȩ��
typedef struct CThostFtdcBrokerUserRightAssignField
{
	///Ӧ�õ�Ԫ����
	TThostFtdcBrokerIDType	BrokerID;
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	DRIdentityID;
	///�ܷ���
	TThostFtdcBoolType	Tradeable;
} CThostFtdcBrokerUserRightAssignField;

///�ֱ�����ת������
typedef struct CThostFtdcDRTransferField
{
	///ԭ�������Ĵ���
	TThostFtdcDRIdentityIDType	OrigDRIdentityID;
	///Ŀ�꽻�����Ĵ���
	TThostFtdcDRIdentityIDType	DestDRIdentityID;
	///ԭӦ�õ�Ԫ����
	TThostFtdcBrokerIDType	OrigBrokerID;
	///Ŀ�����õ�Ԫ����
	TThostFtdcBrokerIDType	DestBrokerID;
} CThostFtdcDRTransferField;

///Fens�û���Ϣ
typedef struct CThostFtdcFensUserInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///��¼ģʽ
	TThostFtdcLoginModeType	LoginMode;
} CThostFtdcFensUserInfoField;

///��ǰ����������������
typedef struct CThostFtdcCurrTransferIdentityField
{
	///�������Ĵ���
	TThostFtdcDRIdentityIDType	IdentityID;
} CThostFtdcCurrTransferIdentityField;

///��ֹ��¼�û�
typedef struct CThostFtdcLoginForbiddenUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///IP��ַ
	TThostFtdcIPAddressType	IPAddress;
} CThostFtdcLoginForbiddenUserField;

///��ѯ��ֹ��¼�û�
typedef struct CThostFtdcQryLoginForbiddenUserField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
} CThostFtdcQryLoginForbiddenUserField;

///UDP�鲥����Ϣ
typedef struct CThostFtdcMulticastGroupInfoField
{
	///�鲥��IP��ַ
	TThostFtdcIPAddressType	GroupIP;
	///�鲥��IP�˿�
	TThostFtdcIPPortType	GroupPort;
	///Դ��ַ
	TThostFtdcIPAddressType	SourceIP;
} CThostFtdcMulticastGroupInfoField;

///�ʽ��˻�����׼����
typedef struct CThostFtdcTradingAccountReserveField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///����׼����
	TThostFtdcMoneyType	Reserve;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
} CThostFtdcTradingAccountReserveField;

///����ԤԼ����ȷ������
typedef struct CThostFtdcReserveOpenAccountConfirmField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///����ID
	TThostFtdcTIDType	TID;
	///Ͷ�����ʺ�
	TThostFtdcAccountIDType	AccountID;
	///�ڻ�����
	TThostFtdcPasswordType	Password;
	///ԤԼ����������ˮ��
	TThostFtdcBankSerialType	BankReserveOpenSeq;
	///ԤԼ��������
	TThostFtdcTradeDateType	BookDate;
	///ԤԼ������֤����
	TThostFtdcPasswordType	BookPsw;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcReserveOpenAccountConfirmField;

///����ԤԼ����
typedef struct CThostFtdcReserveOpenAccountField
{
	///ҵ������
	TThostFtdcTradeCodeType	TradeCode;
	///���д���
	TThostFtdcBankIDType	BankID;
	///���з�֧��������
	TThostFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TThostFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TThostFtdcTradeDateType	TradeDate;
	///����ʱ��
	TThostFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TThostFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TThostFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TThostFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TThostFtdcLastFragmentType	LastFragment;
	///�Ự��
	TThostFtdcSessionIDType	SessionID;
	///�ͻ�����
	TThostFtdcIndividualNameType	CustomerName;
	///֤������
	TThostFtdcIdCardTypeType	IdCardType;
	///֤������
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TThostFtdcGenderType	Gender;
	///���Ҵ���
	TThostFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TThostFtdcCustTypeType	CustType;
	///��ַ
	TThostFtdcAddressType	Address;
	///�ʱ�
	TThostFtdcZipCodeType	ZipCode;
	///�绰����
	TThostFtdcTelephoneType	Telephone;
	///�ֻ�
	TThostFtdcMobilePhoneType	MobilePhone;
	///����
	TThostFtdcFaxType	Fax;
	///�����ʼ�
	TThostFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TThostFtdcBankAccountType	BankAccount;
	///��������
	TThostFtdcPasswordType	BankPassWord;
	///��װ���
	TThostFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TThostFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TThostFtdcDigestType	Digest;
	///�����ʺ�����
	TThostFtdcBankAccTypeType	BankAccType;
	///�ڻ���˾���б���
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///����ID
	TThostFtdcTIDType	TID;
	///ԤԼ����״̬
	TThostFtdcReserveOpenAccStasType	ReserveOpenAccStas;
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
} CThostFtdcReserveOpenAccountField;

///�ּ۱�
typedef struct CThostFtdcMBLMarketDataField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
	///����������
	TThostFtdcExchangeIDType	ExchangeID;
	///����
	TThostFtdcDirectionType	Direction;
	///�۸�
	TThostFtdcPriceType	Price;
	///����
	TThostFtdcVolumeType	Volume;
} CThostFtdcMBLMarketDataField;

///�û�ϵͳ��Ϣ
typedef struct CThostFtdcUserSystemInfoField
{
	///���͹�˾����
	TThostFtdcBrokerIDType	BrokerID;
	///�û�����
	TThostFtdcUserIDType	UserID;
	///�û���ϵͳ�ڲ���Ϣ����
	TThostFtdcSystemInfoLenType	ClientSystemInfoLen;
	///�û���ϵͳ�ڲ���Ϣ
	TThostFtdcClientSystemInfoType	ClientSystemInfo;
	///�û�����IP
	TThostFtdcIPAddressType	ClientPublicIP;
	///�ն�IP�˿�
	TThostFtdcIPPortType	ClientIPPort;
	///��¼�ɹ�ʱ��
	TThostFtdcTimeType	ClientLoginTime;
	///App����
	TThostFtdcClientAppIDType	ClientAppID;
} CThostFtdcUserSystemInfoField;
#endif
