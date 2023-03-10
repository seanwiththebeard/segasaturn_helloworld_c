/*
██╗   ██╗██████╗ ██████╗ ██████╗
██║   ██║██╔══██╗██╔══██╗╚════██╗
██║   ██║██║  ██║██████╔╝ █████╔╝
╚██╗ ██╔╝██║  ██║██╔═══╝ ██╔═══╝
 ╚████╔╝ ██████╔╝██║     ███████╗
  ╚═══╝  ╚═════╝ ╚═╝     ╚══════╝

*/
/** @brief VDP2 I/O register address */
# define JO_VDP2_REG                (0x25F80000)
/** @brief Last VDP2 I/O register address */
# define JO_VDP2_LAST_REG           (0x25F8011E)
/** @brief VDP2 VRAM (512 kilobytes) = A0 + A1 + B0 + B1 */
# define JO_VDP2_VRAM               (0x25E00000)
/** @brief VDP2 VRAM Bank A0 (128 kilobytes) */
# define JO_VDP2_VRAM_A0            (JO_VDP2_VRAM)
/** @brief VDP2 VRAM Bank A1 (128 kilobytes) */
# define JO_VDP2_VRAM_A1            (0x25E20000)
/** @brief VDP2 VRAM Bank B0 (128 kilobytes) */
# define JO_VDP2_VRAM_B0            (0x25E40000)
/** @brief VDP2 VRAM Bank B1 (128 kilobytes) */
# define JO_VDP2_VRAM_B1            (0x25E60000)
/** @brief VDP2 Color RAM (4 kilobytes) */
# define JO_VDP2_CRAM               (0x25F00000)
/** @brief VDP2 VRAM Bank size (128 kilobytes) */
# define JO_VDP2_BANK_SIZE          (0x20000)

# define JO_VDP2_NBG0_CEL_ADR       (VDP2_VRAM_A1)
# define JO_VDP2_NBG0_MAP_ADR       (VDP2_VRAM_B1)
# define JO_VDP2_NBG1_CEL_ADR       (VDP2_VRAM_A0)
# define JO_VDP2_NBG1_MAP_ADR       (VDP2_VRAM_B0)


/* 180002 - r/w - EXTEN - External Signal Enable Register
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       |    --    |    --    |    --    |    --    |    --    |    --    | EXLTEN   | EXSYEN   |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       |    --    |    --    |    --    |    --    |    --    |    --    | DASEL    | EXBGEN   |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_TVMD        (*(volatile unsigned short *)0x25F80000) // 0x8110 0x8120
# define JO_VDP2_EXTEN       (*(volatile unsigned short *)0x25F80002) // 0x0
# define JO_VDP2_TVSTAT      (*(volatile unsigned short *)0x25F80004) // N/A

/* 180006 - r/w - VRSIZE - VRAM Size
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       | VRAMSZ   |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       |    --    |    --    |    --    |    --    | VER3     | VER2     | VER1     | VER0     |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_VRSIZE      (*(volatile unsigned short *)0x25F80006) // 0x0

/* 180008 - r/o - HCNT - H-Counter
  bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
        |    --    |    --    |    --    |    --    |    --    |    --    | HCT9     | HCT8     |
        |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
        | HCT7     | HCT6     | HCT5     | HCT4     | HCT3     | HCT2     | HCT1     | HCT0     |
        \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_HCNT        (*(volatile unsigned short *)0x25F80008) // 0x275 0x26B

/* 18000A - r/o - VCNT - V-Counter
  bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
        |    --    |    --    |    --    |    --    |    --    |    --    | VCT9     | VCT8     |
        |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
        | VCT7     | VCT6     | VCT5     | VCT4     | VCT3     | VCT2     | VCT1     | VCT0     |
        \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_VCNT        (*(volatile unsigned short *)0x25F8000A) // 0x36

/* 18000E - r/w - RAMCTL - RAM Control
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       |  CRKTE   |    --    | CRMD1    | CRMD0    |    --    |    --    | VRBMD    | VRAMD    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       | RDBSB11  | RDBSB10  | RDBSB01  | RDBSB00  | RDBSA11  | RDBSA10  | RDBSA01  | RDBSA00  |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_RAMCTL      (*(volatile unsigned short *)0x25F8000E) // 0x1327

# define JO_VDP2_CYCA0L      (*(volatile unsigned short *)0x25F80010) // 0x5555
# define JO_VDP2_CYCA0U      (*(volatile unsigned short *)0x25F80012) // 0xFEEE
# define JO_VDP2_CYCA1L      (*(volatile unsigned short *)0x25F80014) // 0x5555
# define JO_VDP2_CYCA1U      (*(volatile unsigned short *)0x25F80016) // 0xFEEE
# define JO_VDP2_CYCB0L      (*(volatile unsigned short *)0x25F80018) // 0xFFFF
# define JO_VDP2_CYCB0U      (*(volatile unsigned short *)0x25F8001A) // 0xEEEE
# define JO_VDP2_CYCB1L      (*(volatile unsigned short *)0x25F8001C) // 0x44F
# define JO_VDP2_CYCB1U      (*(volatile unsigned short *)0x25F8001E) // 0xEEEE

/* 180020 - r/w - BGON - SCREEN DISPLAY ENABLE

  this register allows each tilemap to be enabled or disabled and also which layers are solid

  bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
        |    --    |    --    |    --    | R0TPON   | N3TPON   | N2TPON   | N1TPON   | N0TPON   |
        |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
        |    --    |    --    | R1ON     | R0ON     | N3ON     | N2ON     | N1ON     | N0ON     |
        \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_BGON        (*(volatile unsigned short *)0x25F80020) // 0x3

/*
180022 - MZCTL - Mosaic Control
bit->  /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_MZCTL       (*(volatile unsigned short *)0x25F80022) // 0x0
# define JO_VDP2_SFSEL       (*(volatile unsigned short *)0x25F80024) // 0x0
# define JO_VDP2_SFCODE      (*(volatile unsigned short *)0x25F80026) // 0x0
# define JO_VDP2_CHCTLA      (*(volatile unsigned short *)0x25F80028) // 0x3210
# define JO_VDP2_CHCTLB      (*(volatile unsigned short *)0x25F8002A) // 0x1000
/*
18002C - BMPNA - Bitmap Palette Number (NBG0, NBG1)
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_BMPNA       (*(volatile unsigned short *)0x25F8002C) // 0x0

/* 18002E - Bitmap Palette Number (RBG0)
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       |    --    |    --    |    --    |    --    |    --    |    --    |    --    |    --    |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_BMPNB       (*(volatile unsigned short *)0x25F8002E) // 0x0

/* 180030 - PNCN0 - Pattern Name Control (NBG0)
 bit-> /----15----|----14----|----13----|----12----|----11----|----10----|----09----|----08----\
       | N0PNB    | N0CNSM   |    --    |    --    |    --    |    --    | N0SPR    | N0SCC    |
       |----07----|----06----|----05----|----04----|----03----|----02----|----01----|----00----|
       | N0SPLT6  | N0SPLT5  | N0SPLT4  | N0SPCN4  | N0SPCN3  | N0SPCN2  | N0SPCN1  | N0SPCN0  |
       \----------|----------|----------|----------|----------|----------|----------|---------*/
# define JO_VDP2_PNCN0       (*(volatile unsigned short *)0x25F80030) // 0x800C
# define JO_VDP2_PNCN1       (*(volatile unsigned short *)0x25F80032) // 0xC00E
# define JO_VDP2_PNCN2       (*(volatile unsigned short *)0x25F80034) // 0xC000
# define JO_VDP2_PNCN3       (*(volatile unsigned short *)0x25F80036) // 0xC000
# define JO_VDP2_PNCR        (*(volatile unsigned short *)0x25F80038) // 0xC000
# define JO_VDP2_PLSZ        (*(volatile unsigned short *)0x25F8003A) // 0x0
# define JO_VDP2_MPOFN       (*(volatile unsigned short *)0x25F8003C) // 0x0
# define JO_VDP2_MPOFR       (*(volatile unsigned short *)0x25F8003E) // 0x0

# define JO_VDP2_MPABN0      (*(volatile unsigned short *)0x25F80040) // 0x3B3B
# define JO_VDP2_MPCDN0      (*(volatile unsigned short *)0x25F80042) // 0x3B3B
# define JO_VDP2_MPABN1      (*(volatile unsigned short *)0x25F80044) // 0x3939
# define JO_VDP2_MPCDN1      (*(volatile unsigned short *)0x25F80046) // 0x3939
# define JO_VDP2_MPABN2      (*(volatile unsigned short *)0x25F80048) // 0x0
# define JO_VDP2_MPCDN2      (*(volatile unsigned short *)0x25F8004A) // 0x0
# define JO_VDP2_MPABN3      (*(volatile unsigned short *)0x25F8004C) // 0x0
# define JO_VDP2_MPCDN3      (*(volatile unsigned short *)0x25F8004E) // 0x0

# define JO_VDP2_MPABRA      (*(volatile unsigned short *)0x25F80050) // 0x2020
# define JO_VDP2_MPCDRA      (*(volatile unsigned short *)0x25F80052) // 0x2020
# define JO_VDP2_MPEFRA      (*(volatile unsigned short *)0x25F80054) // 0x2020
# define JO_VDP2_MPGHRA      (*(volatile unsigned short *)0x25F80056) // 0x2020
# define JO_VDP2_MPIJRA      (*(volatile unsigned short *)0x25F80058) // 0x2020
# define JO_VDP2_MPKLRA      (*(volatile unsigned short *)0x25F8005A) // 0x2020
# define JO_VDP2_MPMNRA      (*(volatile unsigned short *)0x25F8005C) // 0x2020
# define JO_VDP2_MPOPRA      (*(volatile unsigned short *)0x25F8005E) // 0x2020

# define JO_VDP2_MPABRB      (*(volatile unsigned short *)0x25F80060) // 0x2828
# define JO_VDP2_MPCDRB      (*(volatile unsigned short *)0x25F80062) // 0x2828
# define JO_VDP2_MPEFRB      (*(volatile unsigned short *)0x25F80064) // 0x2828
# define JO_VDP2_MPGHRB      (*(volatile unsigned short *)0x25F80066) // 0x2838
# define JO_VDP2_MPIJRB      (*(volatile unsigned short *)0x25F80068) // 0x2828
# define JO_VDP2_MPKLRB      (*(volatile unsigned short *)0x25F8006A) // 0x2828
# define JO_VDP2_MPMNRB      (*(volatile unsigned short *)0x25F8006C) // 0x2828
# define JO_VDP2_MPOPRB      (*(volatile unsigned short *)0x25F8006E) // 0x2828

# define JO_VDP2_SCXIN0      (*(volatile unsigned short *)0x25F80070) // 0x0
# define JO_VDP2_SCXDN0      (*(volatile unsigned short *)0x25F80072) // 0x0
# define JO_VDP2_SCYIN0      (*(volatile unsigned short *)0x25F80074) // 0x0
# define JO_VDP2_SCYDN0      (*(volatile unsigned short *)0x25F80076) // 0x0
# define JO_VDP2_ZMXIN0      (*(volatile unsigned short *)0x25F80078) // 0x1
# define JO_VDP2_ZMXDN0      (*(volatile unsigned short *)0x25F8007A) // 0x0
# define JO_VDP2_ZMYIN0      (*(volatile unsigned short *)0x25F8007C) // 0x1
# define JO_VDP2_ZMYDN0      (*(volatile unsigned short *)0x25F8007E) // 0x0

# define JO_VDP2_SCXIN1      (*(volatile unsigned short *)0x25F80080) // 0x0
# define JO_VDP2_SCXDN1      (*(volatile unsigned short *)0x25F80082) // 0x0
# define JO_VDP2_SCYIN1      (*(volatile unsigned short *)0x25F80084) // 0x0
# define JO_VDP2_SCYDN1      (*(volatile unsigned short *)0x25F80086) // 0x0
# define JO_VDP2_ZMXIN1      (*(volatile unsigned short *)0x25F80088) // 0x1
# define JO_VDP2_ZMXDN1      (*(volatile unsigned short *)0x25F8008A) // 0x0
# define JO_VDP2_ZMYIN1      (*(volatile unsigned short *)0x25F8008C) // 0x1
# define JO_VDP2_ZMYDN1      (*(volatile unsigned short *)0x25F8008E) // 0x0

# define JO_VDP2_SCXN2       (*(volatile unsigned short *)0x25F80090) // 0x0
# define JO_VDP2_SCYN2       (*(volatile unsigned short *)0x25F80092) // 0x0
# define JO_VDP2_SCXN3       (*(volatile unsigned short *)0x25F80094) // 0x0
# define JO_VDP2_SCYN3       (*(volatile unsigned short *)0x25F80096) // 0x0
# define JO_VDP2_ZMCTL       (*(volatile unsigned short *)0x25F80098) // 0x0
# define JO_VDP2_SCRCTL      (*(volatile unsigned short *)0x25F8009A) // 0x0
# define JO_VDP2_VCSTAU      (*(volatile unsigned short *)0x25F8009C) // 0x0
# define JO_VDP2_VCSTAL      (*(volatile unsigned short *)0x25F8009E) // 0x0

# define JO_VDP2_LSTA0U      (*(volatile unsigned short *)0x25F800A0) // 0x0
# define JO_VDP2_LSTA0L      (*(volatile unsigned short *)0x25F800A2) // 0x0
# define JO_VDP2_LSTA1U      (*(volatile unsigned short *)0x25F800A4) // 0x0
# define JO_VDP2_LSTA1L      (*(volatile unsigned short *)0x25F800A6) // 0x0
# define JO_VDP2_LCTAU       (*(volatile unsigned short *)0x25F800A8) // 0x0
# define JO_VDP2_LCTAL       (*(volatile unsigned short *)0x25F800AA) // 0x0
# define JO_VDP2_BKTAU       (*(volatile unsigned short *)0x25F800AC) // 0x12F1
# define JO_VDP2_BKTAL       (*(volatile unsigned short *)0x25F800AE) // 0xFFFF

# define JO_VDP2_RPMD        (*(volatile unsigned short *)0x25F800B0) // 0x0
# define JO_VDP2_RPRCTL      (*(volatile unsigned short *)0x25F800B2) // 0x0
# define JO_VDP2_KTCTL       (*(volatile unsigned short *)0x25F800B4) // 0x0
# define JO_VDP2_KTAOF       (*(volatile unsigned short *)0x25F800B6) // 0x0
# define JO_VDP2_OVPNRA      (*(volatile unsigned short *)0x25F800B8) // 0x0
# define JO_VDP2_OVPNRB      (*(volatile unsigned short *)0x25F800BA) // 0x0
# define JO_VDP2_RPTAU       (*(volatile unsigned short *)0x25F800BC) // 0x1
# define JO_VDP2_RPTAL       (*(volatile unsigned short *)0x25F800BE) // 0xFF80

# define JO_VDP2_WPSX0       (*(volatile unsigned short *)0x25F800C0) // 0x0
# define JO_VDP2_WPSY0       (*(volatile unsigned short *)0x25F800C2) // 0x0
# define JO_VDP2_WPEX0       (*(volatile unsigned short *)0x25F800C4) // 0x27E  SCRW-1
# define JO_VDP2_WPEY0       (*(volatile unsigned short *)0x25F800C6) // 0x1BE  SCRH-1
# define JO_VDP2_WPSX1       (*(volatile unsigned short *)0x25F800C8) // 0x0
# define JO_VDP2_WPSY1       (*(volatile unsigned short *)0x25F800CA) // 0x0
# define JO_VDP2_WPEX1       (*(volatile unsigned short *)0x25F800CC) // 0x27E  SCRW-1
# define JO_VDP2_WPEY1       (*(volatile unsigned short *)0x25F800CE) // 0x1BE  SCRH-1

# define JO_VDP2_WCTLA       (*(volatile unsigned short *)0x25F800D0) // 0x0
# define JO_VDP2_WCTLB       (*(volatile unsigned short *)0x25F800D2) // 0x0
# define JO_VDP2_WCTLC       (*(volatile unsigned short *)0x25F800D4) // 0x0
# define JO_VDP2_WCTLD       (*(volatile unsigned short *)0x25F800D6) // 0x0
# define JO_VDP2_LWTA0U      (*(volatile unsigned short *)0x25F800D8) // 0x0
# define JO_VDP2_LWTA0L      (*(volatile unsigned short *)0x25F800DA) // 0x0
# define JO_VDP2_LWTA1U      (*(volatile unsigned short *)0x25F800DC) // 0x0
# define JO_VDP2_LWTA1L      (*(volatile unsigned short *)0x25F800DE) // 0x0

# define JO_VDP2_SPCTL       (*(volatile unsigned short *)0x25F800E0) // 0x23
# define JO_VDP2_SDCTL       (*(volatile unsigned short *)0x25F800E2) // 0x0
# define JO_VDP2_CRAOFA      (*(volatile unsigned short *)0x25F800E4) // 0x0
# define JO_VDP2_CRAOFB      (*(volatile unsigned short *)0x25F800E6) // 0x0
# define JO_VDP2_LNCLEN      (*(volatile unsigned short *)0x25F800E8) // 0x0
# define JO_VDP2_SFPRMD      (*(volatile unsigned short *)0x25F800EA) // 0x0
# define JO_VDP2_CCCTL       (*(volatile unsigned short *)0x25F800EC) // 0x0
# define JO_VDP2_SFCCMD      (*(volatile unsigned short *)0x25F800EE) // 0x0

# define JO_VDP2_PRISA       (*(volatile unsigned short *)0x25F800F0) // 0x506
# define JO_VDP2_PRISB       (*(volatile unsigned short *)0x25F800F2) // 0x505
# define JO_VDP2_PRISC       (*(volatile unsigned short *)0x25F800F4) // 0x505
# define JO_VDP2_PRISD       (*(volatile unsigned short *)0x25F800F6) // 0x505
# define JO_VDP2_PRINA       (*(volatile unsigned short *)0x25F800F8) // 0x607
# define JO_VDP2_PRINB       (*(volatile unsigned short *)0x25F800FA) // 0x102
# define JO_VDP2_PRIR        (*(volatile unsigned short *)0x25F800FC) // 0x4
# define JO_VDP2_RESERVE     (*(volatile unsigned short *)0x25F800FE) // 0x0

# define JO_VDP2_CCRSA       (*(volatile unsigned short *)0x25F80100) // 0x0
# define JO_VDP2_CCRSB       (*(volatile unsigned short *)0x25F80102) // 0x0
# define JO_VDP2_CCRSC       (*(volatile unsigned short *)0x25F80104) // 0x0
# define JO_VDP2_CCRSD       (*(volatile unsigned short *)0x25F80106) // 0x0
# define JO_VDP2_CCRNA       (*(volatile unsigned short *)0x25F80108) // 0x0
# define JO_VDP2_CCRNB       (*(volatile unsigned short *)0x25F8010A) // 0x0
# define JO_VDP2_CCRR        (*(volatile unsigned short *)0x25F8010C) // 0x0
# define JO_VDP2_CCRLB       (*(volatile unsigned short *)0x25F8010E) // 0x0

# define JO_VDP2_CLOFEN      (*(volatile unsigned short *)0x25F80110) // 0x0
# define JO_VDP2_CLOFSL      (*(volatile unsigned short *)0x25F80112) // 0x0
# define JO_VDP2_COAR        (*(volatile unsigned short *)0x25F80114) // 0x0
# define JO_VDP2_COAG        (*(volatile unsigned short *)0x25F80116) // 0x0
# define JO_VDP2_COAB        (*(volatile unsigned short *)0x25F80118) // 0x0
# define JO_VDP2_COBR        (*(volatile unsigned short *)0x25F8011A) // 0x0
# define JO_VDP2_COBG        (*(volatile unsigned short *)0x25F8011C) // 0x0
# define JO_VDP2_COBB        (*(volatile unsigned short *)0x25F8011E) // 0x0

#include <jo/jo.h>
#include <stdint.h>
typedef uint8_t byte;
void InitVDP2(void);
//static jo_font      *my_font;
uint16_t* vram = (uint16_t*)0x05E76000;
uint16_t* gfxram = (uint16_t*)0x05E00000;
void setChar(int x, int y, int myChar)
{
    vram[x + y*64] = myChar * 2;
    //jo_printf(x, y, "%c", myChar);
}

void fillvram()
{
    int x = 0;
    for (x = 0; x < 0x76000; ++x)
        if(vram[x] == 0)
            vram[x] = x;
}

void my_update(void)
{
    while(1)
    {
        int x, y, z = 0;
        for (y = 0; y < 16; ++y)
            for (x = 0; x < 16; ++x)
            {
                setChar(x, y, z);
                ++z;
                //jo_set_printf_color_index(JO_COLOR_INDEX_White);
            }

                setChar(24, 18, 'z');

    }
}

void jo_main(void)
{
	jo_core_init(JO_COLOR_Black);
    InitVDP2();
    fillvram();
    //my_font = jo_font_load(JO_ROOT_DIR, "FONT.TGA", JO_COLOR_Green, 8, 8, 2, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"?=%&',.()*+-/");
	//jo_core_add_callback(my_update);
    my_update();
	//jo_core_run();
}


void InitVDP2()
{
    JO_VDP2_HCNT = 0x275; //NTSC
    JO_VDP2_VCNT = 0x36;
    JO_VDP2_RAMCTL = 0x1327;

    JO_VDP2_CYCA0L = 0x5555;
    JO_VDP2_CYCA0U = 0xFEEE;
    JO_VDP2_CYCA1L = 0x5555;
    JO_VDP2_CYCA1U = 0xFEEE;
    JO_VDP2_CYCB0L = 0xFFFF;
    JO_VDP2_CYCB0U = 0xEEEE;
    JO_VDP2_CYCB1L = 0x44F;
    JO_VDP2_CYCB1U = 0xEEEE;

    JO_VDP2_BGON = 0x3;

    JO_VDP2_CHCTLA = 0x3210;
    JO_VDP2_CHCTLB = 0x1000;

    JO_VDP2_PNCN0 = 0x800C;
    JO_VDP2_PNCN1 = 0xC00E;
    JO_VDP2_PNCN2 = 0xC000;
    JO_VDP2_PNCN3 = 0xC000;
    JO_VDP2_PNCR = 0xC000;

    JO_VDP2_MPABN0 = 0x3B3B;
    JO_VDP2_MPCDN0 = 0x3B3B;
    JO_VDP2_MPABN1 = 0x3939;
    JO_VDP2_MPCDN1 = 0x3939;

    JO_VDP2_MPABRA = 0x2020;
    JO_VDP2_MPCDRA = 0x2020;
    JO_VDP2_MPEFRA = 0x2020;
    JO_VDP2_MPGHRA = 0x2020;
    JO_VDP2_MPIJRA = 0x2020;
    JO_VDP2_MPKLRA = 0x2020;
    JO_VDP2_MPMNRA = 0x2020;
    JO_VDP2_MPOPRA = 0x2020;

    JO_VDP2_MPABRB = 0x2828;
    JO_VDP2_MPCDRB = 0x2828;
    JO_VDP2_MPEFRB = 0x2828;
    JO_VDP2_MPGHRB = 0x2838;
    JO_VDP2_MPIJRB = 0x2828;
    JO_VDP2_MPKLRB = 0x2828;
    JO_VDP2_MPMNRB = 0x2828;
    JO_VDP2_MPOPRB = 0x2828;

    JO_VDP2_ZMXIN0 = 0x1;
    JO_VDP2_ZMYIN0 = 0x1;

    JO_VDP2_ZMXIN1 = 0x1;
    JO_VDP2_ZMYIN1 = 0x1;

    JO_VDP2_BKTAU = 0x12F1;
    JO_VDP2_BKTAL = 0xFFFF;

    JO_VDP2_RPTAU = 0x1;
    JO_VDP2_RPTAL = 0xFF80;

    JO_VDP2_WPEX0 = 0x27E;
    JO_VDP2_WPEY0 = 0x1BE;

    JO_VDP2_WPEX1 = 0x27E;
    JO_VDP2_WPEY1 = 0x1BE;

    JO_VDP2_SPCTL = 0x23;

    JO_VDP2_PRISA = 0x506;
    JO_VDP2_PRISB = 0x505;
    JO_VDP2_PRISC = 0x505;
    JO_VDP2_PRISD = 0x505;
    JO_VDP2_PRINA = 0x607;
    JO_VDP2_PRINB = 0x102;
    JO_VDP2_PRIR = 0x4;
}
