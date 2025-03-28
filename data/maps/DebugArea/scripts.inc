DebugArea_MapScripts::
	.byte 0

DebugArea_EventScript_ZLover::
	lock
	faceplayer
	message DebugArea_Text_ZLoverSellWhatYouNeed
	waitmessage
	pokemart DebugArea_Pokemart_ZLover
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
DebugArea_Pokemart_ZLover:
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	pokemartlistend

DebugArea_Text_ZLoverSellWhatYouNeed:
	.string "I'm the Z Lover! I'll go for it and\n"
	.string "sell you what you need!$"


DebugArea_EntreSign::
	msgbox DebugArea_EntreSignText, MSGBOX_SIGN
	end

DebugArea_EntreSignText:
	.string "“Welcome to the debug area!”$"
	