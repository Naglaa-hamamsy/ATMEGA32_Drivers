
#define SET_BIT(REG,BIT_NO) REG|=(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO) REG&=~(1<<BIT_NO)
#define TGL_BIT(REG,BIT_NO) REG^=1<<BIT_NO
#define GET_BIT(REG,BIT_NO) (REG>>BIT_NO)&1
#define SET_HIGH_NIB(REG)   REG|=0xf0
#define CLR_HIGH_NIB(REG)   REG&=0x0f
#define GET_HIGH_NIB(REG)   REG=(REG>>4)&0x0f
#define TGL_HIGH_NIB(REG)   REG^=0xf0
#define SET_LOW_NIB(REG)    REG|=0x0f
#define CLR_LOW_NIB(REG)    REG&=0xf0
#define GET_LOW_NIB(REG)    REG&=0x0f
#define TGL_LOW_NIB(REG)    REG^=0x0f
#define ASSIGN_REG(REG,VALUE) REG=VALUE
#define ASSIGN_HIGH_NIB(REG,VALUE)  REG=(REG&0x0f)|(VALUE<<4)
#define ASSIGN_LOW_NIB(REG,VALUE)  REG=(REG&0xf0)|(VALUE)
#define SHIFT_RIGHT(REG,VALUE)    (REG )>>=VALUE;
#define SHIFT_LEFT(REG,VALUE)      REG<<=VALUE;
#define CRL_SHIFT_RIGHT(REG,VALUE)  REG=((REG>>VALUE)|(REG<<((sizeof(REG)*8)-VALUE)))
#define CRL_SHIFT_LEFT(REG,VALUE)  REG=((REG<<VALUE)|(REG>>((sizeof(REG)*8)-VALUE)))