extends Node

@onready var pause_menu = $CanvasLayer/PauseMenu

var is_paused = false

func _ready():
	var playback = GlobalAudio.get_playback_position()
	GlobalAudio.stop()
	GlobalAudio.set_meta("pos", playback)
	

func _process(delta):
	if Input.is_action_just_pressed("pause"):
		print("handling pause: " + str(is_paused))
		handlePause()


func handlePause():
	if is_paused:
		var playback = GlobalAudio.get_playback_position()
		GlobalAudio.stop()
		GlobalAudio.set_meta("pos", playback)
		pause_menu.hide()
		Engine.time_scale = 1
	else:
		GlobalAudio.play(GlobalAudio.get_meta("pos", 0))
		pause_menu.show()
		Engine.time_scale = 0
	is_paused = !is_paused
