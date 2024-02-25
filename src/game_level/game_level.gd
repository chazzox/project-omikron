extends Node

@onready var pause_menu = $CanvasLayer/PauseMenu


var is_paused = false
	
func _process(delta):
	if Input.is_action_just_pressed("pause"):
		handlePause()

func handlePause():
	if is_paused:
		Utils.pause_music()
		pause_menu.hide()
		Engine.time_scale = 1
	else:
		Utils.play_music()
		pause_menu.show()
		Engine.time_scale = 0
	is_paused = !is_paused
