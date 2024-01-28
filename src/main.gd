extends Node2D

func _on_button_pressed():
	get_tree().root.content_scale_size = get_tree().root.content_scale_size*10
	pass # Replace with function body.


func _on_fullscreen_button_pressed():
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_MAXIMIZED)

