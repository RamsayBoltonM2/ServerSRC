#ifndef __INC_METIN_II_GAME_SHOP_H__
#define __INC_METIN_II_GAME_SHOP_H__

enum
{
	SHOP_MAX_DISTANCE = 1000
};

class CGrid;

/* ---------------------------------------------------------------------------------- */
class CShop
{
	public:
		typedef struct shop_item
		{
			DWORD	vnum;		// ������ ��ȣ
			long	price;		// ����
			long	price_cheque;

			BYTE	count;		// ������ ����

			LPITEM	pkItem;
			int		itemid;		// ������ �������̵�
#ifdef __SHOPEX_SYSTEM__
			long	alSockets[ITEM_SOCKET_MAX_NUM];
			TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
#endif

			shop_item()
			{
				vnum = 0;
				price = 0;

				count = 0;
				itemid = 0;
#ifdef __SHOPEX_SYSTEM__
				alSockets[0] = 0;
				alSockets[1] = 0;
				alSockets[2] = 0;
				alSockets[3] = 0;
				aAttr[0].bType = 0;
				aAttr[0].sValue = 0;
				aAttr[1].bType = 0;
				aAttr[1].sValue = 0;
				aAttr[2].bType = 0;
				aAttr[2].sValue = 0;
				aAttr[3].bType = 0;
				aAttr[3].sValue = 0;
				aAttr[4].bType = 0;
				aAttr[4].sValue = 0;
				aAttr[5].bType = 0;
				aAttr[5].sValue = 0;
				aAttr[6].bType = 0;
				aAttr[6].sValue = 0;
#endif
				pkItem = NULL;
			}
		} SHOP_ITEM;

		CShop();
		~CShop();

		bool SearchItem(LPCHARACTER ch, const char* item_name, int iJob, int iType, int iSubType, int iMinLevel, int iMaxLevel, int iMinRefine, int iMaxRefine, int iMinPrice, int iMaxPrice, int iMinCheque, int iMaxCheque);
#ifdef __SHOPEX_SYSTEM__
		bool	Create(DWORD dwVnum, DWORD dwNPCVnum, TShopItemTable * pItemTable, short price_type, std::string shopname);
#else
		bool	Create(DWORD dwVnum, DWORD dwNPCVnum, TShopItemTable * pItemTable);
#endif
		void	SetShopItems(TShopItemTable * pItemTable, BYTE bItemCount);
		void	SetShopItemsPrivateShop(TShopItemTable2 * pItemTable, BYTE bItemCount);

		virtual void		SetPCShop(LPCHARACTER ch) { m_pkPC = ch; };
		virtual LPCHARACTER GetPCShop() { return m_pkPC; }
		virtual bool		IsPCShop() { return m_pkPC ? true : false; };


		// �Խ�Ʈ �߰�/����
		virtual bool	AddGuest(LPCHARACTER ch,DWORD owner_vid, bool bOtherEmpire);
		void	RemoveGuest(LPCHARACTER ch);

		// ���� ����
		virtual int	Buy(LPCHARACTER ch, BYTE pos);

		// �Խ�Ʈ���� ��Ŷ�� ����
		void	BroadcastUpdateItem(BYTE pos);

		// �Ǹ����� �������� ������ �˷��ش�.
		int		GetNumberByVnum(DWORD dwVnum);

		// �������� ������ ��ϵǾ� �ִ��� �˷��ش�.
		virtual bool	IsSellingItem(DWORD itemID);

		DWORD	GetVnum() { return m_dwVnum; }
		DWORD	GetNPCVnum() { return m_dwNPCVnum; }
		virtual int	BuyFromGlass(LPCHARACTER ch_buyer, BYTE pos);
		void	InsertInMysql(LPCHARACTER lpSeller, LPITEM item, BYTE bPos, DWORD dwItemPrice);
		void	RemoveFromMysql(DWORD dwSellerPID, BYTE bPos);

	protected:
		void	Broadcast(const void * data, int bytes);
		
	protected:
		DWORD				m_dwVnum;
		DWORD				m_dwNPCVnum;
#ifdef __SHOPEX_SYSTEM__
		short				m_sPriceType;
		std::string			m_szShopName;
#endif

		CGrid *				m_pGrid;

		typedef TR1_NS::unordered_map<LPCHARACTER, bool> GuestMapType;
		GuestMapType m_map_guest;
		std::vector<SHOP_ITEM>		m_itemVector;	// �� �������� ����ϴ� ���ǵ�

		LPCHARACTER			m_pkPC;
};

#endif 
