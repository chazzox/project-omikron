extends Node2D

func _on_button_pressed():
	get_tree().root.content_scale_size = get_tree().root.content_scale_size*10

func _on_ready():
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
