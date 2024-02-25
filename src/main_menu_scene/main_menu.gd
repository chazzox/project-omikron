extends Node2D

func _on_ready():
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)

func _on_start_game_pressed():
	Utils.pause_music()
	get_tree().change_scene_to_file("res://src/game_level/game_level.tscn")

func _on_credits_button_pressed():
	get_tree().change_scene_to_file("res://src/credits_scene/credits_menu.tscn")
