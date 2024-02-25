extends Node

@onready var main = $"../../"

func _on_resume_pressed():
	main.handlePause()

func _on_settings_pressed():
	pass # Replace with function body.

func _on_main_menu_pressed():
	get_tree().change_scene_to_file("res://src/main_menu_scene/main_menu.tscn")

func _on_quit_pressed():
	get_tree().quit()

