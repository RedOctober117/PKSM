/*  This file is part of PKSM
>	Copyright (C) 2016/2017 Bernardo Giordano
>
>   Multi-Language support added by Naxann
>
>   This program is free software: you can redistribute it and/or modify
>   it under the terms of the GNU General Public License as published by
>   the Free Software Foundation, either version 3 of the License, or
>   (at your option) any later version.
>
>   This program is distributed in the hope that it will be useful,
>   but WITHOUT ANY WARRANTY; without even the implied warranty of
>   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>   GNU General Public License for more details.
>
>   You should have received a copy of the GNU General Public License
>   along with this program.  If not, see <http://www.gnu.org/licenses/>.
>   See LICENSE for information.
*/

#pragma once
#include "common.h"
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>

// Force the lang to display in PKSM. Useful when debugging another lang than the 3DS lang
// Langs ID are defined in ctrulib : https://smealum.github.io/ctrulib/cfgu_8h.html
// CFG_LANGUAGE_JP = 0
// CFG_LANGUAGE_EN = 1
// CFG_LANGUAGE_FR = 2
// CFG_LANGUAGE_DE = 3
// CFG_LANGUAGE_IT = 4
// CFG_LANGUAGE_ES = 5
// CFG_LANGUAGE_ZH = 6
// CFG_LANGUAGE_KO = 7
// CFG_LANGUAGE_NL = 8
// CFG_LANGUAGE_PT = 9
// CFG_LANGUAGE_RU = 10
// CFG_LANGUAGE_TW = 11
// #define DEBUG_I18N_LANG 5


#define MAX_LANGUAGE 12

/**
 * Localization files
 */
struct i18n_files {
	char *abilities;
	char *species;
	char *natures;
	char *moves;
	char *items;
	char *hp;
	char *forms;
	char *balls;
	char *types;
	char *app;
};

/**
 * Array of strings in UTF32
 */
typedef struct ArrayUTF32 {
	int length;
	wchar_t** items;
	wchar_t** sortedItems;
	int* sortedItemsID;
	bool sorted;
} ArrayUTF32;


/**
 * Labels of localization strings used in the application
 */
typedef enum {
    S_DOWNLOADING_ASSETS = 0,
	S_GUI_ELEMENTS_LOADING_FILES,
	S_GUI_ELEMENTS_LOADING_LOCALES,
	S_GUI_ELEMENTS_LOADING_LOCALES_ABILITIES,
	S_GUI_ELEMENTS_LOADING_LOCALES_MOVES,
	S_GUI_ELEMENTS_LOADING_LOCALES_SORTING_MOVES,
	S_GUI_ELEMENTS_LOADING_LOCALES_NATURES,
	S_GUI_ELEMENTS_LOADING_LOCALES_ITEMS,
	S_GUI_ELEMENTS_LOADING_LOCALES_SORTING_ITEMS,
	S_GUI_ELEMENTS_LOADING_LOCALES_HP,
	S_GUI_ELEMENTS_LOADING_FONTS,
	S_GUI_ELEMENTS_LOADING_FONTS_CACHE_FONT,
	S_GUI_ELEMENTS_LOADING_DONE,

	S_MAIN_CREATING_DEFAULT_BANK,
	S_MAIN_BACKING_UP_BANK,
	S_MAIN_RESTART_APP,
	S_MAIN_MISSING_ASSETS,
	S_MAIN_LOADING_SAVE,
	S_MAIN_GAME_NOT_FOUND,
	S_MAIN_INCORRECT_SAVE_SIZE,
	S_MAIN_NO_CARTRIDGE,

	S_MAIN_MENU_SETTINGS,
	S_MAIN_MENU_EVENTS,
	S_MAIN_MENU_CREDITS,
	S_MAIN_MENU_INDICATION,
	S_MAIN_MENU_INDICATION_EXIT,
	S_MAIN_MENU_EDITOR,
	S_MAIN_MENU_SAVE_INFO,
	S_MAIN_MENU_EXTRA_STORAGE,
	S_MAIN_MENU_MANAGEMENT_MASS_INJECTOR,

	S_MAIN_Q_SAVE_CHANGES,
	S_INFORMATION_MESSAGE_PRESS_A,
	S_CONFIRMATION_MESSAGE_PRESS_A_OR_B,
	S_FREEZEMSG_DEFAULT_DETAILS,

	S_GRAPHIC_GAME_SELECTOR_INFO_CART_HAS_PRIO,
	S_GRAPHIC_GAME_SELECTOR_INDICATIONS,
	S_GRAPHIC_GAME_SELECTOR_GAME_X,
	S_GRAPHIC_GAME_SELECTOR_GAME_Y,
	S_GRAPHIC_GAME_SELECTOR_GAME_OS,
	S_GRAPHIC_GAME_SELECTOR_GAME_AS,
	S_GRAPHIC_GAME_SELECTOR_GAME_SUN,
	S_GRAPHIC_GAME_SELECTOR_GAME_MOON,

	S_GRAPHIC_GAME_SELECTOR_GAME_DIAMOND,
	S_GRAPHIC_GAME_SELECTOR_GAME_PEARL,
	S_GRAPHIC_GAME_SELECTOR_GAME_PLATINUM,
	S_GRAPHIC_GAME_SELECTOR_GAME_HG,
	S_GRAPHIC_GAME_SELECTOR_GAME_SS,
	S_GRAPHIC_GAME_SELECTOR_GAME_B,
	S_GRAPHIC_GAME_SELECTOR_GAME_W,
	S_GRAPHIC_GAME_SELECTOR_GAME_B2,
	S_GRAPHIC_GAME_SELECTOR_GAME_W2,

	S_GRAPHIC_GUI_ELEMENTS_SPECIFY_LOADING,
	S_GRAPHIC_GUI_ELEMENTS_SPECIFY_LOADING_DETAILS,

	S_BANK_SIZE_ERROR,
	S_BANK_Q_ERASE_SELECTED_BOX,
	S_BANK_Q_SAVE_CHANGES,
	S_BANK_Q_SAVE_POKEDEX_FLAGS,
	S_BANK_PROGRESS_MESSAGE,

	S_DATABASE_ERROR_INJECTION,
	S_DATABASE_SUCCESS_INJECTION,
	S_DATABASE_ITEM_NOT_AVAILABLE_XY,
	S_DATABASE_Q_SAVE_POKEDEX_FLAGS,
	S_DATABASE_PROGRESS_MESSAGE,
	S_DATABASE_XD_COLLECTION_SUCCESS,
	S_DATABASE_COLOSSEUM_COLLECTION_SUCCESS,
	S_DATABASE_10TH_ANNIVERSARY_SUCCESS,
	S_DATABASE_N_COLLECTION_SUCCESS,
	S_DATABASE_ENTREE_FOREST_COLLECTION_SUCCESS,
	S_DATABASE_DREAM_RADAR_COLLECTION_SUCCESS,
	S_DATABASE_LIVING_DEX_SUCCESS,
	S_DATABASE_DEOXYS_COLLECTION_SUCCESS,
	S_DATABASE_MY_POKEMON_RANCH_COLLECTION_SUCCESS,
	S_DATABASE_KOREAN_COLLECTION_SUCCESS,

	S_EDITOR_LANGUAGE_SET_SUCCESS,
	S_EDITOR_MISTERY_GIFT_CLEANED,
	S_EDITOR_TEXT_CANCEL,
	S_EDITOR_TEXT_SET,
	S_EDITOR_TEXT_ENTER_NICKNAME_POKEMON,
	S_EDITOR_TEXT_ENTER_TRAINER_NAME,

	S_EDITOR_Q_CONFIRM_RELEASE,
	S_EDITOR_RELEASED,

	S_GRAPHIC_PROGRESSBAR_MESSAGE,
	S_GRAPHIC_MENUDS_EVENTS,
	S_GRAPHIC_MENUDS_OTHER,
	S_GRAPHIC_MENUDS_INDICATIONS,

	S_GRAPHIC_CREDITS_TITLE,
	S_GRAPHIC_CREDITS_INDICATIONS,

	S_GRAPHIC_DB6_TITLE,
	S_GRAPHIC_DB6_INDICATIONS,

	S_GRAPHIC_DB_INDICATIONS_INJECT,
	S_GRAPHIC_DB_INDICATIONS_SELECT,
	S_GRAPHIC_DB_LANGUAGES,
	S_GRAPHIC_DB_OVERWRITE_WC,
	S_GRAPHIC_DB_ADAPT_LANGUAGE_WC,
	S_GRAPHIC_DB_INJECT_WC_SLOT,

	S_GRAPHIC_EDITOR_TITLE,
	S_GRAPHIC_EDITOR_LANGUAGE,
	S_GRAPHIC_EDITOR_CLEAR_MYSTERY_GIFT_BOX,
	S_GRAPHIC_EDITOR_INDICATIONS,

	S_GRAPHIC_INFOVIEWER_NICKNAME,
	S_GRAPHIC_INFOVIEWER_OT,
	S_GRAPHIC_INFOVIEWER_POKERUS,
	S_GRAPHIC_INFOVIEWER_NATURE,
	S_GRAPHIC_INFOVIEWER_ABILITY,
	S_GRAPHIC_INFOVIEWER_ITEM,
	S_GRAPHIC_INFOVIEWER_ESVTSV,
	S_GRAPHIC_INFOVIEWER_TIDSID,
	S_GRAPHIC_INFOVIEWER_HTOT_FRIENDSHIP,
	S_GRAPHIC_INFOVIEWER_HTOT_HIDDEN_POWER,

	S_GRAPHIC_INFOVIEWER_VALUE_HP,
	S_GRAPHIC_INFOVIEWER_VALUE_ATTACK,
	S_GRAPHIC_INFOVIEWER_VALUE_DEFENSE,
	S_GRAPHIC_INFOVIEWER_VALUE_SP_ATK,
	S_GRAPHIC_INFOVIEWER_VALUE_SP_DEF,
	S_GRAPHIC_INFOVIEWER_VALUE_SPEED,
	S_GRAPHIC_INFOVIEWER_LV,

	S_GRAPHIC_INFOVIEWER_MOVES,
	S_GRAPHIC_INFOVIEWER_EGG_CYCLE,

	S_GRAPHIC_PKVIEWER_MENU_EDIT,
	S_GRAPHIC_PKVIEWER_MENU_CLONE,
	S_GRAPHIC_PKVIEWER_MENU_RELEASE,
	S_GRAPHIC_PKVIEWER_MENU_GENERATE,
	S_GRAPHIC_PKVIEWER_MENU_EXIT,
	S_GRAPHIC_PKVIEWER_BOX,
	S_GRAPHIC_PKVIEWER_OTA_LAUNCH_CLIENT,
	S_GRAPHIC_PKVIEWER_OTA_INDICATIONS,
	S_GRAPHIC_PKVIEWER_TEAM,

	S_GRAPHIC_PKVIEWER_CLONE_INDICATIONS,

	S_GRAPHIC_PKVIEWER_MENU_POKEMON_SELECTED,

	S_GRAPHIC_PKVIEWER_GENERATE_INDICATIONS,

	S_GRAPHIC_PKVIEWER_TIDSIDTSV,
	S_GRAPHIC_PKVIEWER_SEED,

	S_GRAPHIC_PKEDITOR_LEVEL,
	S_GRAPHIC_PKEDITOR_NATURE,
	S_GRAPHIC_PKEDITOR_ABILITY,
	S_GRAPHIC_PKEDITOR_ITEM,
	S_GRAPHIC_PKEDITOR_SHINY,
	S_GRAPHIC_PKEDITOR_POKERUS,
	S_GRAPHIC_PKEDITOR_OT,
	S_GRAPHIC_PKEDITOR_NICKNAME,
	S_GRAPHIC_PKEDITOR_FRIENDSHIP,

	S_GRAPHIC_PKEDITOR_MENU_STATS,
	S_GRAPHIC_PKEDITOR_MENU_MOVES,
	S_GRAPHIC_PKEDITOR_MENU_SAVE,

	S_GRAPHIC_PKEDITOR_STATS_HP,
	S_GRAPHIC_PKEDITOR_STATS_ATTACK,
	S_GRAPHIC_PKEDITOR_STATS_DEFENSE,
	S_GRAPHIC_PKEDITOR_STATS_SP_ATTACK,
	S_GRAPHIC_PKEDITOR_STATS_SP_DEFENSE,
	S_GRAPHIC_PKEDITOR_STATS_SPEED,

	S_GRAPHIC_PKEDITOR_BASE_STATS_INDICATIONS_1,
	S_GRAPHIC_PKEDITOR_BASE_STATS_INDICATIONS_2,

	S_GRAPHIC_PKEDITOR_NATURE_NEUTRAL,
	S_GRAPHIC_PKEDITOR_NATURE_MIN_ATTACK,
	S_GRAPHIC_PKEDITOR_NATURE_MIN_DEFENSE,
	S_GRAPHIC_PKEDITOR_NATURE_MIN_SPEED,
	S_GRAPHIC_PKEDITOR_NATURE_MIN_SP_ATTACK,
	S_GRAPHIC_PKEDITOR_NATURE_MIN_SP_DEFENSE,
	S_GRAPHIC_PKEDITOR_NATURE_PLUS_ATTACK,
	S_GRAPHIC_PKEDITOR_NATURE_PLUS_DEFENSE,
	S_GRAPHIC_PKEDITOR_NATURE_PLUS_SPEED,
	S_GRAPHIC_PKEDITOR_NATURE_PLUS_SP_ATTACK,
	S_GRAPHIC_PKEDITOR_NATURE_PLUS_SP_DEFENSE,

	S_GRAPHIC_PKEDITOR_EGG_CYCLE,
	S_GRAPHIC_PKEDITOR_LBL_STATS,
	S_GRAPHIC_PKEDITOR_LBL_IV,
	S_GRAPHIC_PKEDITOR_LBL_EV,
	S_GRAPHIC_PKEDITOR_LBL_TOTAL,
	S_GRAPHIC_PKEDITOR_HIDDEN_POWER,

	S_GRAPHIC_PKEDITOR_MOVES,
	S_GRAPHIC_PKEDITOR_RELEARN_MOVES,
	S_GRAPHIC_PKEDITOR_SELECTED_BYTE,

	S_GRAPHIC_PKEDITOR_ITEM_INDICATION,
	S_GRAPHIC_PKEDITOR_NATURE_INDICATION,
	S_GRAPHIC_PKEDITOR_BALL_INDICATION,
	S_GRAPHIC_PKEDITOR_HP_INDICATION,
	S_GRAPHIC_PKEDITOR_FORM_INDICATION,

	S_GRAPHIC_PKBANK_BANK_TITLE,
	S_GRAPHIC_PKBANK_LV_PKMN,
	S_GRAPHIC_PKBANK_OTID_PKMN,
	S_GRAPHIC_PKBANK_SAVED_BOX_TITLE,

	S_GRAPHIC_PKBANK_MENU_VIEW,
	S_GRAPHIC_PKBANK_MENU_CLEARBOX,
	S_GRAPHIC_PKBANK_MENU_RELEASE,

	S_GRAPHIC_MASSINJECTOR_XD_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_COLOSSEUM_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_10TH_ANNIV_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_N_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_ENTREE_FOREST_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_DREAM_RADAR_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_LIVING_DEX,
	S_GRAPHIC_MASSINJECTOR_OBLIVIA_DEOXYS_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_PKMN_RANCH_COLLECTION,
	S_GRAPHIC_MASSINJECTOR_KOR_EVENTS_COLLECTION,

	S_GRAPHIC_MASSINJECTOR_MESSAGE_REPLACE_BOXES,
	S_GRAPHIC_MASSINJECTOR_TITLE,
	S_GRAPHIC_MASSINJECTOR_INDICATION,

	S_GRAPHIC_SETTINGS_BANK_SIZE,
	S_GRAPHIC_SETTINGS_BACKUP_SAVE,
	S_GRAPHIC_SETTINGS_BACKUP_BANK,
	S_GRAPHIC_SETTINGS_INDICATION,

	S_YES,
	S_NO,

	S_GRAPHIC_HEXEDITOR_SPECIES,
	S_GRAPHIC_HEXEDITOR_HELD_ITEM,
	S_GRAPHIC_HEXEDITOR_TID,
	S_GRAPHIC_HEXEDITOR_SID,
	S_GRAPHIC_HEXEDITOR_ABILITY,
	S_GRAPHIC_HEXEDITOR_NATURE,

	S_GRAPHIC_HEXEDITOR_FATEFUL_ENCOUNTER_FLAG,
	S_GRAPHIC_HEXEDITOR_GENDER,
	S_GRAPHIC_HEXEDITOR_GENDER_MALE,
	S_GRAPHIC_HEXEDITOR_GENDER_FEMALE,
	S_GRAPHIC_HEXEDITOR_GENDER_GENDERLESS,
	S_GRAPHIC_HEXEDITOR_ALTERNATIVE_FORM,

	S_GRAPHIC_HEXEDITOR_EV_HP,
	S_GRAPHIC_HEXEDITOR_EV_ATK,
	S_GRAPHIC_HEXEDITOR_EV_DEF,
	S_GRAPHIC_HEXEDITOR_EV_SPE,
	S_GRAPHIC_HEXEDITOR_EV_SPA,
	S_GRAPHIC_HEXEDITOR_EV_SPD,

	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_COOL,
	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_BEAUTY,
	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_CUTE,
	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_SMART,
	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_TOUGH,
	S_GRAPHIC_HEXEDITOR_CONTEST_VALUE_SHEEN,

	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_KALOS,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_G3_HOENN,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_SINNOH,
	S_GRAPHIC_HEXEDITOR_RIBBON_BEST_FRIENDS,
	S_GRAPHIC_HEXEDITOR_RIBBON_TRAINING,
	S_GRAPHIC_HEXEDITOR_RIBBON_SKILLFUL_BATTLER,
	S_GRAPHIC_HEXEDITOR_RIBBON_BATTLER_EXPERT,
	S_GRAPHIC_HEXEDITOR_RIBBON_EFFORT,

	S_GRAPHIC_HEXEDITOR_RIBBON_ALERT,
	S_GRAPHIC_HEXEDITOR_RIBBON_SHOCK,
	S_GRAPHIC_HEXEDITOR_RIBBON_DOWNCAST,
	S_GRAPHIC_HEXEDITOR_RIBBON_CARELESS,
	S_GRAPHIC_HEXEDITOR_RIBBON_RELAX,
	S_GRAPHIC_HEXEDITOR_RIBBON_SNOOZE,
	S_GRAPHIC_HEXEDITOR_RIBBON_SMILE,
	S_GRAPHIC_HEXEDITOR_RIBBON_GORGEOUS,

	S_GRAPHIC_HEXEDITOR_RIBBON_ROYAL,
	S_GRAPHIC_HEXEDITOR_RIBBON_GORGEOUS_ROYAL,
	S_GRAPHIC_HEXEDITOR_RIBBON_ARTIST,
	S_GRAPHIC_HEXEDITOR_RIBBON_FOOTPRINT,
	S_GRAPHIC_HEXEDITOR_RIBBON_RECORD,
	S_GRAPHIC_HEXEDITOR_RIBBON_LEGEND,
	S_GRAPHIC_HEXEDITOR_RIBBON_COUNTRY,
	S_GRAPHIC_HEXEDITOR_RIBBON_NATIONAL,

	S_GRAPHIC_HEXEDITOR_RIBBON_EARTH,
	S_GRAPHIC_HEXEDITOR_RIBBON_WORLD,
	S_GRAPHIC_HEXEDITOR_RIBBON_CLASSIC,
	S_GRAPHIC_HEXEDITOR_RIBBON_PREMIER,
	S_GRAPHIC_HEXEDITOR_RIBBON_EVENT,
	S_GRAPHIC_HEXEDITOR_RIBBON_BIRTHDAY,
	S_GRAPHIC_HEXEDITOR_RIBBON_SPECIAL,
	S_GRAPHIC_HEXEDITOR_RIBBON_SOUVENIR,

	S_GRAPHIC_HEXEDITOR_RIBBON_WISHING,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_BATTLE,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_REGIONAL,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_NATIONAL,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_WORLD,
	S_GRAPHIC_HEXEDITOR_RIBBON_38,
	S_GRAPHIC_HEXEDITOR_RIBBON_39,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_G6_HOENN,

	S_GRAPHIC_HEXEDITOR_RIBBON_CONTEST_STAR,
	S_GRAPHIC_HEXEDITOR_RIBBON_MASTER_COOLNESS,
	S_GRAPHIC_HEXEDITOR_RIBBON_MASTER_BEAUTY,
	S_GRAPHIC_HEXEDITOR_RIBBON_MASTER_CUTENESS,
	S_GRAPHIC_HEXEDITOR_RIBBON_MASTER_CLEVERNESS,
	S_GRAPHIC_HEXEDITOR_RIBBON_MASTER_TOUGHNESS,
	S_GRAPHIC_HEXEDITOR_RIBBON_CHAMPION_ALOLA,
	S_GRAPHIC_HEXEDITOR_RIBBON_BATTLE_ROYALE,

	S_GRAPHIC_HEXEDITOR_RIBBON_BATTLE_TREE_GREAT,
	S_GRAPHIC_HEXEDITOR_RIBBON_BATTLE_TREE_MASTER,
	S_GRAPHIC_HEXEDITOR_RIBBON_51,
	S_GRAPHIC_HEXEDITOR_RIBBON_52,
	S_GRAPHIC_HEXEDITOR_RIBBON_53,
	S_GRAPHIC_HEXEDITOR_RIBBON_54,
	S_GRAPHIC_HEXEDITOR_RIBBON_55,
	S_GRAPHIC_HEXEDITOR_RIBBON_56,

	S_GRAPHIC_HEXEDITOR_NICKNAME,

	S_GRAPHIC_HEXEDITOR_MOVE1,
	S_GRAPHIC_HEXEDITOR_MOVE2,
	S_GRAPHIC_HEXEDITOR_MOVE3,
	S_GRAPHIC_HEXEDITOR_MOVE4,

	S_GRAPHIC_HEXEDITOR_MOVE1_PP,
	S_GRAPHIC_HEXEDITOR_MOVE2_PP,
	S_GRAPHIC_HEXEDITOR_MOVE3_PP,
	S_GRAPHIC_HEXEDITOR_MOVE4_PP,

	S_GRAPHIC_HEXEDITOR_MOVE1_PPUP,
	S_GRAPHIC_HEXEDITOR_MOVE2_PPUP,
	S_GRAPHIC_HEXEDITOR_MOVE3_PPUP,
	S_GRAPHIC_HEXEDITOR_MOVE4_PPUP,

	S_GRAPHIC_HEXEDITOR_RELEARN_MOVE1,
	S_GRAPHIC_HEXEDITOR_RELEARN_MOVE2,
	S_GRAPHIC_HEXEDITOR_RELEARN_MOVE3,
	S_GRAPHIC_HEXEDITOR_RELEARN_MOVE4,

	S_GRAPHIC_HEXEDITOR_IS_NICKNAMED,
	S_GRAPHIC_HEXEDITOR_IS_EGG,

	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_NAME,
	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_FRIENDSHIP,
	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_AFFECTION,
	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_INTENSITY,
	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_MEMORY,
	S_GRAPHIC_HEXEDITOR_HELD_TRAINER_FEELING,

	S_GRAPHIC_HEXEDITOR_FULLNESS,
	S_GRAPHIC_HEXEDITOR_ENJOYMENT,

	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_NAME,
	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_FRIENDSHIP,
	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_AFFECTION,
	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_INTENSITY,
	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_MEMORY,
	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_FEELING,

	S_GRAPHIC_HEXEDITOR_EGG_YEAR,
	S_GRAPHIC_HEXEDITOR_EGG_MONTH,
	S_GRAPHIC_HEXEDITOR_EGG_DAY,

	S_GRAPHIC_HEXEDITOR_MET_YEAR,
	S_GRAPHIC_HEXEDITOR_MET_MONTH,
	S_GRAPHIC_HEXEDITOR_MET_DAY,
	S_GRAPHIC_HEXEDITOR_MET_LEVEL,

	S_GRAPHIC_HEXEDITOR_ORIGINAL_TRAINER_GENDER,

	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_HP,
	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_ATK,
	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_DEF,
	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_SPATK,
	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_SPDEF,
	S_GRAPHIC_HEXEDITOR_HYPER_TRAINED_SPEED,


	S_HEXEDITOR_DESC_0x00,
	S_HEXEDITOR_DESC_0x01,
	S_HEXEDITOR_DESC_0x02,
	S_HEXEDITOR_DESC_0x03,
	S_HEXEDITOR_DESC_0x04,
	S_HEXEDITOR_DESC_0x05,
	S_HEXEDITOR_DESC_0x06,
	S_HEXEDITOR_DESC_0x07,
	S_HEXEDITOR_DESC_0x08,
	S_HEXEDITOR_DESC_0x09,
	S_HEXEDITOR_DESC_0x0A,
	S_HEXEDITOR_DESC_0x0B,
	S_HEXEDITOR_DESC_0x0C,
	S_HEXEDITOR_DESC_0x0D,
	S_HEXEDITOR_DESC_0x0E,
	S_HEXEDITOR_DESC_0x0F,
	S_HEXEDITOR_DESC_0x10,
	S_HEXEDITOR_DESC_0x11,
	S_HEXEDITOR_DESC_0x12,
	S_HEXEDITOR_DESC_0x13,
	S_HEXEDITOR_DESC_0x14,
	S_HEXEDITOR_DESC_0x15,
	S_HEXEDITOR_DESC_0x16,
	S_HEXEDITOR_DESC_0x17,
	S_HEXEDITOR_DESC_0x18,
	S_HEXEDITOR_DESC_0x19,
	S_HEXEDITOR_DESC_0x1A,
	S_HEXEDITOR_DESC_0x1B,
	S_HEXEDITOR_DESC_0x1C,
	S_HEXEDITOR_DESC_0x1D,
	S_HEXEDITOR_DESC_0x1E,
	S_HEXEDITOR_DESC_0x1F,
	S_HEXEDITOR_DESC_0x20,
	S_HEXEDITOR_DESC_0x21,
	S_HEXEDITOR_DESC_0x22,
	S_HEXEDITOR_DESC_0x23,
	S_HEXEDITOR_DESC_0x24,
	S_HEXEDITOR_DESC_0x25,
	S_HEXEDITOR_DESC_0x26,
	S_HEXEDITOR_DESC_0x27,
	S_HEXEDITOR_DESC_0x28,
	S_HEXEDITOR_DESC_0x29,
	S_HEXEDITOR_DESC_0x2A,
	S_HEXEDITOR_DESC_0x2B,
	S_HEXEDITOR_DESC_0x2C,
	S_HEXEDITOR_DESC_0x2D,
	S_HEXEDITOR_DESC_0x2E,
	S_HEXEDITOR_DESC_0x2F,
	S_HEXEDITOR_DESC_0x30,
	S_HEXEDITOR_DESC_0x31,
	S_HEXEDITOR_DESC_0x32,
	S_HEXEDITOR_DESC_0x33,
	S_HEXEDITOR_DESC_0x34,
	S_HEXEDITOR_DESC_0x35,
	S_HEXEDITOR_DESC_0x36,
	S_HEXEDITOR_DESC_0x37,
	S_HEXEDITOR_DESC_0x38,
	S_HEXEDITOR_DESC_0x39,
	S_HEXEDITOR_DESC_0x3A,
	S_HEXEDITOR_DESC_0x40,
	S_HEXEDITOR_DESC_0x41,
	S_HEXEDITOR_DESC_0x42,
	S_HEXEDITOR_DESC_0x43,
	S_HEXEDITOR_DESC_0x44,
	S_HEXEDITOR_DESC_0x45,
	S_HEXEDITOR_DESC_0x46,
	S_HEXEDITOR_DESC_0x47,
	S_HEXEDITOR_DESC_0x48,
	S_HEXEDITOR_DESC_0x49,
	S_HEXEDITOR_DESC_0x4A,
	S_HEXEDITOR_DESC_0x4B,
	S_HEXEDITOR_DESC_0x4C,
	S_HEXEDITOR_DESC_0x4D,
	S_HEXEDITOR_DESC_0x4E,
	S_HEXEDITOR_DESC_0x4F,
	S_HEXEDITOR_DESC_0x50,
	S_HEXEDITOR_DESC_0x51,
	S_HEXEDITOR_DESC_0x52,
	S_HEXEDITOR_DESC_0x53,
	S_HEXEDITOR_DESC_0x54,
	S_HEXEDITOR_DESC_0x55,
	S_HEXEDITOR_DESC_0x56,
	S_HEXEDITOR_DESC_0x57,
	S_HEXEDITOR_DESC_0x5A,
	S_HEXEDITOR_DESC_0x5B,
	S_HEXEDITOR_DESC_0x5C,
	S_HEXEDITOR_DESC_0x5D,
	S_HEXEDITOR_DESC_0x5E,
	S_HEXEDITOR_DESC_0x5F,
	S_HEXEDITOR_DESC_0x60,
	S_HEXEDITOR_DESC_0x61,
	S_HEXEDITOR_DESC_0x62,
	S_HEXEDITOR_DESC_0x63,
	S_HEXEDITOR_DESC_0x64,
	S_HEXEDITOR_DESC_0x65,
	S_HEXEDITOR_DESC_0x66,
	S_HEXEDITOR_DESC_0x67,
	S_HEXEDITOR_DESC_0x68,
	S_HEXEDITOR_DESC_0x69,
	S_HEXEDITOR_DESC_0x6A,
	S_HEXEDITOR_DESC_0x6B,
	S_HEXEDITOR_DESC_0x6C,
	S_HEXEDITOR_DESC_0x6D,
	S_HEXEDITOR_DESC_0x6E,
	S_HEXEDITOR_DESC_0x6F,
	S_HEXEDITOR_DESC_0x70,
	S_HEXEDITOR_DESC_0x71,
	S_HEXEDITOR_DESC_0x72,
	S_HEXEDITOR_DESC_0x74,
	S_HEXEDITOR_DESC_0x75,
	S_HEXEDITOR_DESC_0x76,
	S_HEXEDITOR_DESC_0x77,
	S_HEXEDITOR_DESC_0x78,
	S_HEXEDITOR_DESC_0x79,
	S_HEXEDITOR_DESC_0x7A,
	S_HEXEDITOR_DESC_0x7B,
	S_HEXEDITOR_DESC_0x7C,
	S_HEXEDITOR_DESC_0x7D,
	S_HEXEDITOR_DESC_0x7E,
	S_HEXEDITOR_DESC_0x7F,
	S_HEXEDITOR_DESC_0x80,
	S_HEXEDITOR_DESC_0x81,
	S_HEXEDITOR_DESC_0x82,
	S_HEXEDITOR_DESC_0x83,
	S_HEXEDITOR_DESC_0x84,
	S_HEXEDITOR_DESC_0x85,
	S_HEXEDITOR_DESC_0x86,
	S_HEXEDITOR_DESC_0x87,
	S_HEXEDITOR_DESC_0x88,
	S_HEXEDITOR_DESC_0x89,
	S_HEXEDITOR_DESC_0x8A,
	S_HEXEDITOR_DESC_0x8B,
	S_HEXEDITOR_DESC_0x8C,
	S_HEXEDITOR_DESC_0x8D,
	S_HEXEDITOR_DESC_0x8E,
	S_HEXEDITOR_DESC_0x8F,
	S_HEXEDITOR_DESC_0x92,
	S_HEXEDITOR_DESC_0x93,
	S_HEXEDITOR_DESC_0x94,
	S_HEXEDITOR_DESC_0x95,
	S_HEXEDITOR_DESC_0x96,
	S_HEXEDITOR_DESC_0x97,
	S_HEXEDITOR_DESC_0x98,
	S_HEXEDITOR_DESC_0x99,
	S_HEXEDITOR_DESC_0x9A,
	S_HEXEDITOR_DESC_0x9B,
	S_HEXEDITOR_DESC_0x9C,
	S_HEXEDITOR_DESC_0x9D,
	S_HEXEDITOR_DESC_0xA2,
	S_HEXEDITOR_DESC_0xA3,
	S_HEXEDITOR_DESC_0xA4,
	S_HEXEDITOR_DESC_0xA5,
	S_HEXEDITOR_DESC_0xA6,
	S_HEXEDITOR_DESC_0xA8,
	S_HEXEDITOR_DESC_0xA9,
	S_HEXEDITOR_DESC_0xAE,
	S_HEXEDITOR_DESC_0xAF,
	S_HEXEDITOR_DESC_0xB0,
	S_HEXEDITOR_DESC_0xB1,
	S_HEXEDITOR_DESC_0xB2,
	S_HEXEDITOR_DESC_0xB3,
	S_HEXEDITOR_DESC_0xB4,
	S_HEXEDITOR_DESC_0xB5,
	S_HEXEDITOR_DESC_0xB6,
	S_HEXEDITOR_DESC_0xB7,
	S_HEXEDITOR_DESC_0xB8,
	S_HEXEDITOR_DESC_0xB9,
	S_HEXEDITOR_DESC_0xBA,
	S_HEXEDITOR_DESC_0xBB,
	S_HEXEDITOR_DESC_0xBC,
	S_HEXEDITOR_DESC_0xBD,
	S_HEXEDITOR_DESC_0xBE,
	S_HEXEDITOR_DESC_0xBF,
	S_HEXEDITOR_DESC_0xC0,
	S_HEXEDITOR_DESC_0xC1,
	S_HEXEDITOR_DESC_0xC2,
	S_HEXEDITOR_DESC_0xC3,
	S_HEXEDITOR_DESC_0xC4,
	S_HEXEDITOR_DESC_0xC5,
	S_HEXEDITOR_DESC_0xC6,
	S_HEXEDITOR_DESC_0xC7,
	S_HEXEDITOR_DESC_0xCA,
	S_HEXEDITOR_DESC_0xCB,
	S_HEXEDITOR_DESC_0xCC,
	S_HEXEDITOR_DESC_0xCD,
	S_HEXEDITOR_DESC_0xCE,
	S_HEXEDITOR_DESC_0xD0,
	S_HEXEDITOR_DESC_0xD1,
	S_HEXEDITOR_DESC_0xD2,
	S_HEXEDITOR_DESC_0xD3,
	S_HEXEDITOR_DESC_0xD4,
	S_HEXEDITOR_DESC_0xD5,
	S_HEXEDITOR_DESC_0xD6,
	S_HEXEDITOR_DESC_0xD8,
	S_HEXEDITOR_DESC_0xDA,
	S_HEXEDITOR_DESC_0xDC,
	S_HEXEDITOR_DESC_0xDD,
	S_HEXEDITOR_DESC_0xDE,
	S_HEXEDITOR_DESC_0xDF,
	S_HEXEDITOR_DESC_0xE0,
	S_HEXEDITOR_DESC_0xE1,
	S_HEXEDITOR_DESC_0xE2,
	S_HEXEDITOR_DESC_0xE3,

	S_HTTP_SERVER_RUNNING,
	S_HTTP_BUFFER_ALLOC_FAILED,
	S_HTTP_SOCINIT_FAILED,
	S_HTTP_SOCKET_UNACCESSIBLE,
	S_HTTP_BINDING_FAILED,
	S_HTTP_LISTENING_FAILED,
	S_HTTP_ERROR_PROCESSING_PHASE,

	S_HTTP_HTTP_CONTEXT_OPEN_FAILED,
	S_HTTP_DOWNLOAD_ASSETS_FAILED,
	S_HTTP_ADD_REQUEST_HEADER_FIELD_FAILED,
	S_HTTP_SET_SSLOPT_FAILED,
	S_HTTP_BEGIN_HTTP_REQUEST_FAILED,
	S_HTTP_RECEIVE_STATUS_CODE_FAILED,
	S_HTTP_REDIRECTION_FAILED,
	S_HTTP_RECEIVE_DOWNLOAD_SIZE_FAILED,
	S_HTTP_ALLOC_MEMORY_FAILED,

	S_UTIL_BANK_CHANGING_SIZE,
	S_UTIL_BANK_SIZE_CHANGED,
	S_UTIL_BACKUP_SAVE_CREATED,
	S_UTIL_BACKUP_BANK_CREATED,
	
	S_GRAPHIC_PKBANK_MENU_DUMP,
	S_GRAPHIC_PKBANK_MESSAGE_CONFIRM_DUMP,
	S_GRAPHIC_PKBANK_MESSAGE_DUMP,
	S_GRAPHIC_PKBANK_MENU_DEX,
	S_GRAPHIC_PKBANK_CAUGHT,
	S_GRAPHIC_PKBANK_SEEN,
	
	S_SOCKET_CONNECT_FAILED,
	S_SOCKET_SEND_FAILED,
	S_EDITOR_TEXT_ENTER_LEGALITY_ADDRESS,
	S_GRAPHIC_PKVIEWER_OTA_SET_ADDRESS,
	S_GRAPHIC_PKVIEWER_OTA_CHECK_LEGALITY,
	
	S_HTTP_CALLING_GITHUB_API,
	S_HTTP_ELABORATING_API_RESPONSE,
	S_HTTP_DOWNLOADING_UPDATE,
	S_HTTP_UPDATE_FAILED,
	S_HTTP_ERROR_CERT,
	S_HTTP_ERROR_REQUEST_HEADER,
	S_HTTP_ERROR_DOWNLOAD_DATA,
	S_HTTP_INSTALL_UPDATE,
	S_HTTP_UPDATE_INSTALLED,
	
	S_LAUNCH_GAME,
} AppTextCode;


struct ArrayUTF32 i18n_FileToArrayUTF32(char* filepath);
void i18n_free_ArrayUTF32(ArrayUTF32 *arr);

struct i18n_files i18n_getFilesPath();

// struct ArrayUTF32 ArrayUTF32_copy(struct ArrayUTF32 from);
void ArrayUTF32_sort_starting_index(ArrayUTF32 *arr, int index);
void ArrayUTF32_sort_starting_index_with_sort_func(struct ArrayUTF32 *arr, int index, int (*f)(const wchar_t *a,const wchar_t *b));
void ArrayUTF32_sort(ArrayUTF32 *arr);
void debuglogf(const char* format, ...);

wchar_t* i18n(AppTextCode code);
void i18n_init();
void i18n_initTextSwkbd(SwkbdState* swkbd, AppTextCode leftButtonTextCode, AppTextCode rightButtonTextCode, AppTextCode hintTextCode);
void i18n_exit();

