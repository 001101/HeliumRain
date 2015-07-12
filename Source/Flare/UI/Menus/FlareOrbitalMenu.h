#pragma once

#include "../../Flare.h"


class AFlareMenuManager;


class SFlareOrbitalMenu : public SCompoundWidget
{
	/*----------------------------------------------------
		Slate arguments
	----------------------------------------------------*/

	SLATE_BEGIN_ARGS(SFlareOrbitalMenu){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AFlareMenuManager>, MenuManager)
	
	SLATE_END_ARGS()


public:

	/*----------------------------------------------------
		Interaction
	----------------------------------------------------*/

	/** Create the widget */
	void Construct(const FArguments& InArgs);

	/** Setup the widget */
	void Setup();

	/** Enter this menu */
	void Enter();

	/** Exit this menu */
	void Exit();


protected:

	/*----------------------------------------------------
		Drawing
	----------------------------------------------------*/

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& ClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	/** Draw an orbit path between two points */
	void DrawOrbitPath(const FGeometry& AllottedGeometry, const FSlateRect& ClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	                   FVector2D PlanetCenter, int32 RadiusA, int32 AngleA, int32 RadiusB, int32 AngleB) const;


	/*----------------------------------------------------
		Callbacks
	----------------------------------------------------*/

	/** Back to the main menu */
	void OnMainMenu();

	/** Exit this menu */
	void OnExit();


protected:

	/*----------------------------------------------------
		Protected data
	----------------------------------------------------*/
	
	// Game data
	AFlareGame*                                 Game;
	TWeakObjectPtr<class AFlareMenuManager>     MenuManager;
	
};
