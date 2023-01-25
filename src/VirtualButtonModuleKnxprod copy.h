#pragma once

//#define paramDelay(time) (uint32_t)((time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : (time & 0xC000) = 0x4000 ? (time & 0x3FFF) * 60000 : (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : (time & 0x3FFF) * 3600000 ) : 0 )
#define paramDelay(base, time) \
  (uint32_t)( \
    (base == 3) ? (time * 100) : \
    (base == 0) ? (time * 1000) : \
    (base == 1) ? (time * 60000) : \
    (base == 2 && time >= 1000) ? (3600000000) : \
    (base == 2 && time < 1000) ? (3600000 * time) : \
    0 \
  )
  
// Parameter with single occurrence


#define BTN_ReactionTimeMultiClick     0      // 8 Bits, Bit 7-0
#define BTN_ReactionTimeLong           1      // 8 Bits, Bit 7-0
#define BTN_ReactionTimeExtraLong      2      // 8 Bits, Bit 7-0

//   Mehrfach-Klick
#define ParamBTN_ReactionTimeMultiClick    (knx.paramByte(BTN_ReactionTimeMultiClick))
//   Langer Tasterdruck
#define ParamBTN_ReactionTimeLong          (knx.paramByte(BTN_ReactionTimeLong))
//   Extra langer Tastedruck
#define ParamBTN_ReactionTimeExtraLong     (knx.paramByte(BTN_ReactionTimeExtraLong))

#define BTN_ChannelCount 5

// Parameter per channel
#define BTN_ParamBlockOffset 4
#define BTN_ParamBlockSize 51
#define BTN_ParamCalcIndex(index) (index + BTN_ParamBlockOffset + _channelIndex * BTN_ParamBlockSize)

#define BTN_ChannelMode                0      // 4 Bits, Bit 7-4
#define     BTN_ChannelModeMask 0xF0
#define     BTN_ChannelModeShift 4
#define BTN_ChannelLock                0      // 2 Bits, Bit 3-2
#define     BTN_ChannelLockMask 0x0C
#define     BTN_ChannelLockShift 2
#define BTN_ChannelMultiClickCount     0      // 1 Bit, Bit 3
#define     BTN_ChannelMultiClickCountMask 0x08
#define     BTN_ChannelMultiClickCountShift 3
#define BTN_ChannelInputA              1      // 16 Bits, Bit 15-0
#define BTN_ChannelInputB              3      // 16 Bits, Bit 15-0
#define BTN_ChannelReactionTimeMultiClick  5      // 8 Bits, Bit 7-0
#define BTN_ChannelReactionTimeLong    6      // 8 Bits, Bit 7-0
#define BTN_ChannelReactionTimeExtraLong  7      // 8 Bits, Bit 7-0
#define BTN_ChannelOutputShort_DPT     8      // 8 Bits, Bit 7-0
#define BTN_ChannelOutputLong_DPT      9      // 8 Bits, Bit 7-0
#define BTN_ChannelOutputExtraLong_DPT 10      // 8 Bits, Bit 7-0
#define BTN_ChannelOutputMulti_DPT    11      // 8 Bits, Bit 7-0
#define BTN_ChannelOutputMulti_Click1_Active 12      // 1 Bit, Bit 7
#define     BTN_ChannelOutputMulti_Click1_ActiveMask 0x80
#define     BTN_ChannelOutputMulti_Click1_ActiveShift 7
#define BTN_ChannelOutputMulti_Click2_Active 12      // 1 Bit, Bit 6
#define     BTN_ChannelOutputMulti_Click2_ActiveMask 0x40
#define     BTN_ChannelOutputMulti_Click2_ActiveShift 6
#define BTN_ChannelOutputMulti_Click3_Active 12      // 1 Bit, Bit 5
#define     BTN_ChannelOutputMulti_Click3_ActiveMask 0x20
#define     BTN_ChannelOutputMulti_Click3_ActiveShift 5
#define BTN_ChannelOutputShort_Taster1_Active_Press 13      // 1 Bit, Bit 7
#define     BTN_ChannelOutputShort_Taster1_Active_PressMask 0x80
#define     BTN_ChannelOutputShort_Taster1_Active_PressShift 7
#define BTN_ChannelOutputShort_Taster1_Active_Release 13      // 1 Bit, Bit 6
#define     BTN_ChannelOutputShort_Taster1_Active_ReleaseMask 0x40
#define     BTN_ChannelOutputShort_Taster1_Active_ReleaseShift 6
#define BTN_ChannelOutputShort_Taster2_Active_Press 13      // 1 Bit, Bit 5
#define     BTN_ChannelOutputShort_Taster2_Active_PressMask 0x20
#define     BTN_ChannelOutputShort_Taster2_Active_PressShift 5
#define BTN_ChannelOutputShort_Taster2_Active_Release 13      // 1 Bit, Bit 4
#define     BTN_ChannelOutputShort_Taster2_Active_ReleaseMask 0x10
#define     BTN_ChannelOutputShort_Taster2_Active_ReleaseShift 4
#define BTN_ChannelOutputLong_Taster1_Active_Press 14      // 1 Bit, Bit 7
#define     BTN_ChannelOutputLong_Taster1_Active_PressMask 0x80
#define     BTN_ChannelOutputLong_Taster1_Active_PressShift 7
#define BTN_ChannelOutputLong_Taster1_Active_Release 14      // 1 Bit, Bit 6
#define     BTN_ChannelOutputLong_Taster1_Active_ReleaseMask 0x40
#define     BTN_ChannelOutputLong_Taster1_Active_ReleaseShift 6
#define BTN_ChannelOutputLong_Taster2_Active_Press 14      // 1 Bit, Bit 5
#define     BTN_ChannelOutputLong_Taster2_Active_PressMask 0x20
#define     BTN_ChannelOutputLong_Taster2_Active_PressShift 5
#define BTN_ChannelOutputLong_Taster2_Active_Release 14      // 1 Bit, Bit 4
#define     BTN_ChannelOutputLong_Taster2_Active_ReleaseMask 0x10
#define     BTN_ChannelOutputLong_Taster2_Active_ReleaseShift 4
#define BTN_ChannelOutputExtraLong_Taster1_Active_Press 15      // 1 Bit, Bit 7
#define     BTN_ChannelOutputExtraLong_Taster1_Active_PressMask 0x80
#define     BTN_ChannelOutputExtraLong_Taster1_Active_PressShift 7
#define BTN_ChannelOutputExtraLong_Taster1_Active_Release 15      // 1 Bit, Bit 6
#define     BTN_ChannelOutputExtraLong_Taster1_Active_ReleaseMask 0x40
#define     BTN_ChannelOutputExtraLong_Taster1_Active_ReleaseShift 6
#define BTN_ChannelOutputExtraLong_Taster2_Active_Press 15      // 1 Bit, Bit 5
#define     BTN_ChannelOutputExtraLong_Taster2_Active_PressMask 0x20
#define     BTN_ChannelOutputExtraLong_Taster2_Active_PressShift 5
#define BTN_ChannelOutputExtraLong_Taster2_Active_Release 15      // 1 Bit, Bit 4
#define     BTN_ChannelOutputExtraLong_Taster2_Active_ReleaseMask 0x10
#define     BTN_ChannelOutputExtraLong_Taster2_Active_ReleaseShift 4
#define BTN_ChannelOutputShort_Taster1_Dpt1_Press 16      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt1_Release 18      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt1_Press 20      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt1_Release 24      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt1_Press 26      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt1_Release 28      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt1_Press 30      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt1_Release 32      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press 34      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release 36      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press 38      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release 40      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click1_Dpt1 42      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click2_Dpt1 44      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click3_Dpt1 46      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt2_Press 16      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt2_Release 18      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt2_Press 20      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt2_Release 24      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt2_Press 26      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt2_Release 28      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt2_Press 30      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt2_Release 32      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press 34      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release 36      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press 38      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt2_Release 40      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click1_Dpt2 42      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click2_Dpt2 44      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click3_Dpt2 46      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt5_Press 16      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt5_Release 18      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt5_Press 20      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt5_Release 24      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt5_Press 26      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt5_Release 28      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt5_Press 30      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt5_Release 32      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press 34      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release 36      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press 38      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release 40      // uint16_t
#define BTN_ChannelOutputMulti_Click1_Dpt5 42      // uint16_t
#define BTN_ChannelOutputMulti_Click2_Dpt5 44      // uint16_t
#define BTN_ChannelOutputMulti_Click3_Dpt5 46      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Press 16      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Release 18      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Press 20      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Release 24      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Press 26      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Release 28      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Press 30      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Release 32      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press 34      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release 36      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press 38      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release 40      // uint16_t
#define BTN_ChannelOutputMulti_Click1_Dpt5001 42      // uint16_t
#define BTN_ChannelOutputMulti_Click2_Dpt5001 44      // uint16_t
#define BTN_ChannelOutputMulti_Click3_Dpt5001 46      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt7_Press 16      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt7_Release 18      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt7_Press 20      // uint16_t
#define BTN_ChannelOutputShort_Taster2_Dpt7_Release 24      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt7_Press 26      // uint16_t
#define BTN_ChannelOutputLong_Taster1_Dpt7_Release 28      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt7_Press 30      // uint16_t
#define BTN_ChannelOutputLong_Taster2_Dpt7_Release 32      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press 34      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release 36      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press 38      // uint16_t
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release 40      // uint16_t
#define BTN_ChannelOutputMulti_Click1_Dpt7 42      // uint16_t
#define BTN_ChannelOutputMulti_Click2_Dpt7 44      // uint16_t
#define BTN_ChannelOutputMulti_Click3_Dpt7 46      // uint16_t
#define BTN_ChannelOutputShort_Taster1_Dpt18_Press 16      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt18_Release 18      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt18_Press 20      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt18_Release 24      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt18_Press 26      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt18_Release 28      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt18_Press 30      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt18_Release 32      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press 34      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release 36      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press 38      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release 40      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click1_Dpt18 42      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click2_Dpt18 44      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputMulti_Click3_Dpt18 46      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Press 16      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Release 18      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Press 20      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Release 24      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Press 26      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Release 28      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Press 30      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Release 32      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press 34      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release 36      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press 38      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release 40      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Press 16      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Release 18      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Press 20      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Release 24      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Press 26      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Release 28      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Press 30      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Release 32      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press 34      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release 36      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press 38      // 16 Bits, Bit 15-0
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release 40      // 16 Bits, Bit 15-0
#define BTN_ChannelOutput2Short_Taster1 46      // 2 Bits, Bit 7-6
#define     BTN_ChannelOutput2Short_Taster1Mask 0xC0
#define     BTN_ChannelOutput2Short_Taster1Shift 6
#define BTN_ChannelOutput2Short_Taster2 46      // 2 Bits, Bit 5-4
#define     BTN_ChannelOutput2Short_Taster2Mask 0x30
#define     BTN_ChannelOutput2Short_Taster2Shift 4
#define BTN_ChannelOutput2Long_Taster1 46      // 2 Bits, Bit 3-2
#define     BTN_ChannelOutput2Long_Taster1Mask 0x0C
#define     BTN_ChannelOutput2Long_Taster1Shift 2
#define BTN_ChannelOutput2Long_Taster2 46      // 2 Bits, Bit 1-0
#define     BTN_ChannelOutput2Long_Taster2Mask 0x03
#define     BTN_ChannelOutput2Long_Taster2Shift 0
#define BTN_ChannelOutput2ExtraLong_Taster1 47      // 2 Bits, Bit 7-6
#define     BTN_ChannelOutput2ExtraLong_Taster1Mask 0xC0
#define     BTN_ChannelOutput2ExtraLong_Taster1Shift 6
#define BTN_ChannelOutput2ExtraLong_Taster2 47      // 2 Bits, Bit 5-4
#define     BTN_ChannelOutput2ExtraLong_Taster2Mask 0x30
#define     BTN_ChannelOutput2ExtraLong_Taster2Shift 4
#define BTN_ChannelStatusThreshold    48      // uint8_t
#define BTN_ChannelStatusFallbackBase 49      // 2 Bits, Bit 7-6
#define     BTN_ChannelStatusFallbackBaseMask 0xC0
#define     BTN_ChannelStatusFallbackBaseShift 6
#define BTN_ChannelStatusFallbackTime 49      // 14 Bits, Bit 13-0
#define     BTN_ChannelStatusFallbackTimeMask 0x3FFF
#define     BTN_ChannelStatusFallbackTimeShift 0

// Modus
#define ParamBTN_ChannelMode               ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelMode)) & BTN_ChannelModeMask) >> BTN_ChannelModeShift)
// Sperre
#define ParamBTN_ChannelLock               ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelLock)) & BTN_ChannelLockMask) >> BTN_ChannelLockShift)
// Ausgabe der Klickanzahl
#define ParamBTN_ChannelMultiClickCount    ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelMultiClickCount)) & BTN_ChannelMultiClickCountMask))
// 1. Taster
#define ParamBTN_ChannelInputA             (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelInputA)))
// 2. Taster
#define ParamBTN_ChannelInputB             (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelInputB)))
//   Mehrfach-Klick
#define ParamBTN_ChannelReactionTimeMultiClick (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelReactionTimeMultiClick)))
//   Langer Tasterdruck
#define ParamBTN_ChannelReactionTimeLong   (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelReactionTimeLong)))
//   Extra langer Tasterdruck
#define ParamBTN_ChannelReactionTimeExtraLong (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelReactionTimeExtraLong)))
// Datentyp
#define ParamBTN_ChannelOutputShort_DPT    (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputShort_DPT)))
// Datentyp
#define ParamBTN_ChannelOutputLong_DPT     (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputLong_DPT)))
// Datentyp
#define ParamBTN_ChannelOutputExtraLong_DPT (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_DPT)))
// Datentyp
#define ParamBTN_ChannelOutputMulti_DPT    (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_DPT)))
// 1. Klick
#define ParamBTN_ChannelOutputMulti_Click1_Active ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Active)) & BTN_ChannelOutputMulti_Click1_ActiveMask))
// 2. Klick
#define ParamBTN_ChannelOutputMulti_Click2_Active ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Active)) & BTN_ChannelOutputMulti_Click2_ActiveMask))
// 3. Klick
#define ParamBTN_ChannelOutputMulti_Click3_Active ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Active)) & BTN_ChannelOutputMulti_Click3_ActiveMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster1_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Active_Press)) & BTN_ChannelOutputShort_Taster1_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster1_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Active_Release)) & BTN_ChannelOutputShort_Taster1_Active_ReleaseMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster2_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Active_Press)) & BTN_ChannelOutputShort_Taster2_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster2_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Active_Release)) & BTN_ChannelOutputShort_Taster2_Active_ReleaseMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster1_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Active_Press)) & BTN_ChannelOutputLong_Taster1_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster1_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Active_Release)) & BTN_ChannelOutputLong_Taster1_Active_ReleaseMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster2_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Active_Press)) & BTN_ChannelOutputLong_Taster2_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster2_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Active_Release)) & BTN_ChannelOutputLong_Taster2_Active_ReleaseMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Active_Press)) & BTN_ChannelOutputExtraLong_Taster1_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Active_Release)) & BTN_ChannelOutputExtraLong_Taster1_Active_ReleaseMask))
//   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Press ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Active_Press)) & BTN_ChannelOutputExtraLong_Taster2_Active_PressMask))
//   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Release ((bool)(knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Active_Release)) & BTN_ChannelOutputExtraLong_Taster2_Active_ReleaseMask))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt1 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt1)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt1 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt1)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt1 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt1)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt2_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt2 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt2)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt2 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt2)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt2 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt2)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt5)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt5)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt5)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5001 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt5001)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5001 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt5001)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5001 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt5001)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt7 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt7)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt7 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt7)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt7 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt7)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release)))
// 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt18 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click1_Dpt18)))
// 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt18 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click2_Dpt18)))
// 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt18 (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputMulti_Click3_Dpt18)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster1_Dpt3008_Release)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputShort_Taster2_Dpt3008_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster1_Dpt3008_Release)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputLong_Taster2_Dpt3008_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press)))
// 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release)))
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster1 ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2Short_Taster1)) & BTN_ChannelOutput2Short_Taster1Mask) >> BTN_ChannelOutput2Short_Taster1Shift)
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster2 ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2Short_Taster2)) & BTN_ChannelOutput2Short_Taster2Mask) >> BTN_ChannelOutput2Short_Taster2Shift)
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster1 ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2Long_Taster1)) & BTN_ChannelOutput2Long_Taster1Mask) >> BTN_ChannelOutput2Long_Taster1Shift)
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster2 (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2Long_Taster2)) & BTN_ChannelOutput2Long_Taster2Mask)
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster1 ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2ExtraLong_Taster1)) & BTN_ChannelOutput2ExtraLong_Taster1Mask) >> BTN_ChannelOutput2ExtraLong_Taster1Shift)
//   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster2 ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelOutput2ExtraLong_Taster2)) & BTN_ChannelOutput2ExtraLong_Taster2Mask) >> BTN_ChannelOutput2ExtraLong_Taster2Shift)
// Schwellwert
#define ParamBTN_ChannelStatusThreshold    (knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelStatusThreshold)))
// Zeitbasis
#define ParamBTN_ChannelStatusFallbackBase ((knx.paramByte(BTN_ParamCalcIndex(BTN_ChannelStatusFallbackBase)) & BTN_ChannelStatusFallbackBaseMask) >> BTN_ChannelStatusFallbackBaseShift)
// Zeit
#define ParamBTN_ChannelStatusFallbackTime (knx.paramWord(BTN_ParamCalcIndex(BTN_ChannelStatusFallbackTime)) & BTN_ChannelStatusFallbackTimeMask)
// Zeit (in Millisekunden)
#define ParamBTN_ChannelStatusFallbackTimeMS (paramDelay(ParamBTN_ChannelStatusFallbackBase, ParamBTN_ChannelStatusFallbackTime))

// deprecated
#define BTN_KoOffset 400

// Communication objects per channel (multiple occurrence)
#define BTN_KoBlockOffset 400
#define BTN_KoBlockSize 12

#define BTN_KoCalcNumber(index) (index + BTN_KoBlockOffset + _channelIndex * BTN_KoBlockSize)
#define BTN_KoCalcIndex(number) (((number - BTN_KoBlockOffset) >= 0) ? (number - BTN_KoOffset) % BTN_KoBlockSize : -1)

#define BTN_KoChannelLock 0
#define BTN_KoChannelInput1 1
#define BTN_KoChannelInput2 2
#define BTN_KoChannelOutput1Status 3
#define BTN_KoChannelOutput2Status 4
#define BTN_KoChannelOutput3Status 5
#define BTN_KoChannelOutput1 6
#define BTN_KoChannelOutput2 7
#define BTN_KoChannelOutput3 8
#define BTN_KoChannelOutput4 9
#define BTN_KoChannelOutput5 10
#define BTN_KoChannelOutput6 11

// 
#define KoBTN_ChannelLock               (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelLock)))
// 
#define KoBTN_ChannelInput1             (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelInput1)))
// 
#define KoBTN_ChannelInput2             (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelInput2)))
// 
#define KoBTN_ChannelOutput1Status      (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput1Status)))
// 
#define KoBTN_ChannelOutput2Status      (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput2Status)))
// 
#define KoBTN_ChannelOutput3Status      (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput3Status)))
// 
#define KoBTN_ChannelOutput1            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput1)))
// 
#define KoBTN_ChannelOutput2            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput2)))
// 
#define KoBTN_ChannelOutput3            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput3)))
// 
#define KoBTN_ChannelOutput4            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput4)))
// 
#define KoBTN_ChannelOutput5            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput5)))
// 
#define KoBTN_ChannelOutput6            (knx.getGroupObject(BTN_KoCalcNumber(BTN_KoChannelOutput6)))


#define MAIN_OpenKnxId 0xA3
#define MAIN_ApplicationNumber 3
#define MAIN_ApplicationVersion 1
#define MAIN_OrderNumber "VBM"
