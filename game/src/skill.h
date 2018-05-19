#ifndef __INC_METIN_II_GAME_CSkillManager_H__
#define __INC_METIN_II_GAME_CSkillManager_H__

#include "../../libpoly/Poly.h"
#include "../../common/service.h"

enum ESkillFlags
{
	SKILL_FLAG_ATTACK			= (1 << 0),	// ���� ���
	SKILL_FLAG_USE_MELEE_DAMAGE		= (1 << 1),	// �⺻ �и� Ÿ��ġ�� b ������ ���
	SKILL_FLAG_COMPUTE_ATTGRADE		= (1 << 2),	// ���ݵ���� ����Ѵ�
	SKILL_FLAG_SELFONLY			= (1 << 3),	// �ڽſ��Ը� �� �� ����
	SKILL_FLAG_USE_MAGIC_DAMAGE		= (1 << 4),	// �⺻ ���� Ÿ��ġ�� b ������ ���
	SKILL_FLAG_USE_HP_AS_COST		= (1 << 5),	// HP�� SP��� ����
	SKILL_FLAG_COMPUTE_MAGIC_DAMAGE	= (1 << 6),
	SKILL_FLAG_SPLASH			= (1 << 7),
	SKILL_FLAG_GIVE_PENALTY		= (1 << 8),	// �������� ��õ���(3��) 2�� �������� �޴´�.
	SKILL_FLAG_USE_ARROW_DAMAGE		= (1 << 9),	// �⺻ ȭ�� Ÿ��ġ�� b ������ ���
	SKILL_FLAG_PENETRATE		= (1 << 10),	// ����
	SKILL_FLAG_IGNORE_TARGET_RATING	= (1 << 11),	// ��� ������ ����
	SKILL_FLAG_SLOW			= (1 << 12),	// ���ο� ����
	SKILL_FLAG_STUN			= (1 << 13),	// ���� ����
	SKILL_FLAG_HP_ABSORB		= (1 << 14),	// HP ����
	SKILL_FLAG_SP_ABSORB		= (1 << 15),	// SP ����
	SKILL_FLAG_FIRE_CONT		= (1 << 16),	// FIRE ���� ������
	SKILL_FLAG_REMOVE_BAD_AFFECT	= (1 << 17),	// ����ȿ�� ����
	SKILL_FLAG_REMOVE_GOOD_AFFECT	= (1 << 18),	// ����ȿ�� ����
	SKILL_FLAG_CRUSH			= (1 << 19),	// ������ ����
	SKILL_FLAG_POISON			= (1 << 20),	// �� ����
	SKILL_FLAG_TOGGLE			= (1 << 21),	// ���
	SKILL_FLAG_DISABLE_BY_POINT_UP	= (1 << 22),	// �� �ø� �� ����.
	SKILL_FLAG_CRUSH_LONG		= (1 << 23),	// ������ �ָ� ����
	SKILL_FLAG_WIND		= (1 << 24),	// �ٶ� �Ӽ�
	SKILL_FLAG_ELEC		= (1 << 25),	// ���� �Ӽ�
	SKILL_FLAG_FIRE		= (1 << 26),	// �� �Ӽ�
#ifdef __YMIR_UPDATE_WOLFMAN__
	SKILL_FLAG_BLEEDING	= (1 << 27),
	SKILL_FLAG_PARTY	= (1 << 28),
#endif
};

enum
{
	SKILL_PENALTY_DURATION = 3,
	SKILL_TYPE_HORSE = 5,
};

enum ESkillIndexes
{
	SKILL_RESERVED = 0,

	// ���� ���� �迭
	// A
	SKILL_SAMYEON = 1,		// �￬��(��������)
	SKILL_PALBANG,		// �ȹ�ǳ��
	// S
	SKILL_JEONGWI,		// ����ȥ
	SKILL_GEOMKYUNG,		// �˰�
	SKILL_TANHWAN,		// źȯ��

	// ���� ��� �迭
	// A
	SKILL_GIGONGCHAM = 16,	// �����
	SKILL_GYOKSAN,		// �ݻ�Ÿ��
	SKILL_DAEJINGAK,		// ������
	// S
	SKILL_CHUNKEON,		// õ����
	SKILL_GEOMPUNG,		// ��ǳ

	// �ڰ� �ϻ� �迭
	// A
	SKILL_AMSEOP = 31,		// �Ͻ�
	SKILL_GUNGSIN,		// �ý�ź��
	SKILL_CHARYUN,		// ������
	// S
	SKILL_EUNHYUNG,		// ������
	SKILL_SANGONG,		// �����

	// �ڰ� �ü� �迭
	// A
	SKILL_YEONSA = 46,		// ����
	SKILL_KWANKYEOK,		// ���ݼ�
	SKILL_HWAJO,		// ȭ����
	// S
	SKILL_GYEONGGONG,		// �����
	SKILL_GIGUNG,		// ���

	// ���� ��
	// A
	SKILL_SWAERYUNG = 61,	// �����
	SKILL_YONGKWON,		// �����
	// S
	SKILL_GWIGEOM,		// �Ͱ�
	SKILL_TERROR,		// ����
	SKILL_JUMAGAP,		// �ָ���
	SKILL_PABEOB,		// �Ĺ���

	// ���� ����
	// A
	SKILL_MARYUNG = 76,		// ����
	SKILL_HWAYEOMPOK,		// ȭ����
	SKILL_MUYEONG,		// ������
	// S
	SKILL_MANASHILED,		// ��ż�ȣ
	SKILL_TUSOK,		// ���Ӹ���
	SKILL_MAHWAN,		// ��ȯ��

	// ���� ���
	// A
	SKILL_BIPABU = 91,
	SKILL_YONGBI,		// ��񱤻���
	SKILL_PAERYONG,		// �з泪�ѹ�
	// S
	//SKILL_BUDONG,		// �ε��ں�
	SKILL_HOSIN,		// ȣ��
	SKILL_REFLECT,		// ��ȣ
	SKILL_GICHEON,		// ��õ���

	// ���� ����
	// A
	SKILL_NOEJEON = 106,	// ������
	SKILL_BYEURAK,		// ����
	SKILL_CHAIN,		// ü�ζ���Ʈ��
	// S
	SKILL_JEONGEOP,		// ������
	SKILL_KWAESOK,		// �̵��ӵ���
	SKILL_JEUNGRYEOK,		// ���¼�

	// ���� ��ų
	// 7
	SKILL_7_A_ANTI_TANHWAN = 112,
	SKILL_7_B_ANTI_AMSEOP,
	SKILL_7_C_ANTI_SWAERYUNG,
	SKILL_7_D_ANTI_YONGBI,

	// 8
	SKILL_8_A_ANTI_GIGONGCHAM,
	SKILL_8_B_ANTI_YEONSA,
	SKILL_8_C_ANTI_MAHWAN,
	SKILL_8_D_ANTI_BYEURAK,

	// ���� ��ų

	SKILL_LEADERSHIP = 121,	// ��ַ�
	SKILL_COMBO	= 122,		// �����
	SKILL_CREATE = 123,		// ����
	SKILL_MINING = 124,

	SKILL_LANGUAGE1 = 126,	// �ż��� �ɷ�
	SKILL_LANGUAGE2 = 127,	// õ���� �ɷ�
	SKILL_LANGUAGE3 = 128,	// ����� �ɷ�
	SKILL_POLYMORPH = 129,	// �а�

	SKILL_HORSE			= 130,	// �¸� ��ų
	SKILL_HORSE_SUMMON		= 131,	// �� ��ȯ ��ų
	SKILL_HORSE_WILDATTACK	= 137,	// ����
	SKILL_HORSE_CHARGE		= 138,	// ����
	SKILL_HORSE_ESCAPE		= 139,	// Ż��
	SKILL_HORSE_WILDATTACK_RANGE = 140,	// ����(Ȱ)

	SKILL_ADD_HP	=	141,			// ����
	SKILL_RESIST_PENETRATE	=	142,	// ö��

	GUILD_SKILL_START = 151,
	GUILD_SKILL_EYE = 151,
	GUILD_SKILL_BLOOD = 152,
	GUILD_SKILL_BLESS = 153,
	GUILD_SKILL_SEONGHWI = 154,
	GUILD_SKILL_ACCEL = 155,
	GUILD_SKILL_BUNNO = 156,
	GUILD_SKILL_JUMUN = 157,
	GUILD_SKILL_TELEPORT = 158,
	GUILD_SKILL_DOOR = 159,
	GUILD_SKILL_END = 162,

	GUILD_SKILL_COUNT = GUILD_SKILL_END - GUILD_SKILL_START + 1,
#ifdef __YMIR_UPDATE_WOLFMAN__
	// ������ ��ų
	SKILL_CHAYEOL		= 170,			// ���� (����) : ���밡 �ٶ��� ������ ���� ���� �߱�� : �� ���ݷ� %.0f-%.0f ũ��Ƽ�� Ȯ�� ����, ���� Ȯ�� %.0f%% ���� ���ʽ� // ���� �￬��
	SKILL_SALPOONG		= 171,			// ��ǳ (����) : �������� ������ �θ��� �ٶ��� ����Ų��. // ���� ��ǳ
	SKILL_GONGDAB		= 172,			// ������ (����) : ����� ��� ���� �����Ѵ�. // �ڰ� õ����Ÿ (��� ��ȹ���� ���ִµ� ������ų���� �𸣰��� -_-;)
	SKILL_PASWAE		= 173,			// �ļ� (����) : ����� ������ ���� �߱��. // ���� �￬�� (��, 1ȸ�� Ÿ��)
	SKILL_JEOKRANG		= 174,			// �������� (����) : ���� ������ ��ȥ�� �����Ѵ�. // ���ݷ� +%.0f, ���� -%.0f, �̵� �ӵ� -%.0f, ��� ��� ���� Ȯ�� %.0f%% // ���� õ����
	SKILL_CHEONGRANG	= 175,			// û������ (����) : Ǫ�� ������ ��ȥ�� �����Ѵ�. // ���ݷ� -%.0f, ���� -%.0f, �̵� �ӵ� +%.0f, ���� Ȯ���� ���� ����
#endif

#ifdef __7AND8TH_SKILLS__
	SKILL_ANTI_PALBANG = 221,
	SKILL_ANTI_AMSEOP = 222,
	SKILL_ANTI_SWAERYUNG = 223,
	SKILL_ANTI_YONGBI = 224,
	SKILL_ANTI_GIGONGCHAM = 225,
	SKILL_ANTI_HWAJO = 226,
	SKILL_ANTI_MARYUNG = 227,
	SKILL_ANTI_BYEURAK = 228,
#ifdef __WOLFMAN_CHARACTER__
	SKILL_ANTI_SALPOONG = 229,
#endif
	SKILL_HELP_PALBANG = 236,
	SKILL_HELP_AMSEOP = 237,
	SKILL_HELP_SWAERYUNG = 238,
	SKILL_HELP_YONGBI = 239,
	SKILL_HELP_GIGONGCHAM = 240,
	SKILL_HELP_HWAJO = 241,
	SKILL_HELP_MARYUNG = 242,
	SKILL_HELP_BYEURAK = 243,
#ifdef __WOLFMAN_CHARACTER__
	SKILL_HELP_SALPOONG = 244,
#endif
#endif

};

class CSkillProto
{
	public:
		char	szName[64];
		DWORD	dwVnum;			// ��ȣ

		DWORD	dwType;			// 0: ������, 1: ����, 2: �ڰ�, 3: ����, 4: ����, 5: ��, 6: ��, 7: ������
		BYTE	bMaxLevel;		// �ִ� ���õ�
		BYTE	bLevelLimit;		// ��������
		int	iSplashRange;		// ���÷��� �Ÿ� ����

		BYTE	bPointOn;		// ��� ������� ���� ��Ű�°�? (Ÿ��ġ, MAX HP, HP REGEN ����)
		CPoly	kPointPoly;		// ����� ����� ����

		CPoly	kSPCostPoly;		// ��� SP ����
		CPoly	kDurationPoly;		// ���� �ð� ����
		CPoly	kDurationSPCostPoly;	// ���� SP ����
		CPoly	kCooldownPoly;		// ��ٿ� �ð� ����
		CPoly	kMasterBonusPoly;	// �������� �� ���ʽ� ����
		CPoly	kSplashAroundDamageAdjustPoly;	// ���÷��� ������ ��� ���� ������ ������ ������ ���� ����

		DWORD	dwFlag;			// ��ų�ɼ�
		DWORD	dwAffectFlag;		// ��ų�� ���� ��� ����Ǵ� Affect

		BYTE	bLevelStep;		// �ѹ��� �ø��µ� �ʿ��� ��ų ����Ʈ ��
		DWORD	preSkillVnum;		// ���µ� �ʿ��� ������ ������� ��ų
		BYTE	preSkillLevel;		// ������ ������� ��ų�� ����

		long	lMaxHit;

		BYTE	bSkillAttrType;

		// 2�� ����
		BYTE	bPointOn2;
		CPoly	kPointPoly2;
		CPoly	kDurationPoly2;
		DWORD	dwFlag2;
		DWORD	dwAffectFlag2;

		DWORD   dwTargetRange;

		bool	IsChargeSkill()
		{
			return dwVnum == SKILL_TANHWAN || dwVnum == SKILL_HORSE_CHARGE;
		}

		// 3�� ����
		BYTE bPointOn3;
		CPoly kPointPoly3;
		CPoly kDurationPoly3;

		CPoly kGrandMasterAddSPCostPoly;

		void SetPointVar(const std::string& strName, double dVar);
		void SetDurationVar(const std::string& strName, double dVar);
		void SetSPCostVar(const std::string& strName, double dVar);
};

class CSkillManager : public singleton<CSkillManager>
{
	public:
		CSkillManager();
		virtual ~CSkillManager();

		bool Initialize(TSkillTable * pTab, int iSize);
		CSkillProto * Get(DWORD dwVnum);
		CSkillProto * Get(const char * c_pszSkillName);

	protected:
		std::map<DWORD, CSkillProto *> m_map_pkSkillProto;
};

#endif