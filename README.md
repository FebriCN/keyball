# keyball44:easy

_The original Keyball Series README please check [here](https://github.com/Yowkees/keyball)._

I have been an HHKB user for 12 years, and when I came across the Keyball, I developed a strong interest in it.

So I bought one, then the story started.

I made my own keymap, [keyball44:easy](./qmk_firmware/keyboards/keyball/keyball44/keymaps/easy), it's my first time to write QMK related things.

## Features

- Update QMK Firmware to the latest, currently [0.26.8](https://github.com/qmk/qmk_firmware/releases/tag/0.26.8)
- Features Enabled: [Space Cadet](https://docs.qmk.fm/features/space_cadet), [Key Override](https://docs.qmk.fm/features/key_overrides), [Combo Keys](https://docs.qmk.fm/features/combo), [Tap Dance](https://docs.qmk.fm/features/tap_dance)
- Features Disabled: Any Light, Grave Esc

## Layers
- Layer 0
  - This is the default layer
- Layer 1 **(has number-row keys and navigation keys, and <kbd>-/_</kbd>, <kbd>=/+</kbd>, <kbd>'/"</kbd>)**  
  To activate:
  - Hold <kbd>Space</kbd>
  - Tap the key on the right of the track ball (<kbd>TG(1)</kbd>) will `Toggle Layer 1` (to use number-row keys)
- Layer 2 **(has Fn-row keys, mouse left/right clicks, audio adjust, screen brightness adjust)**  
  To activate:
  - Hold <kbd>Esc</kbd> (when mouse clicks is needed but AutoMouseLayer not activated, or to use right-side keys)
  - Hold <kbd>Shift</kbd> + <kbd>TG(1)</kbd> (to use left-side keys)
  - A movement beyond 64 will `Activate Layer 2` automatically.
- Layer 3 **(has no keys, but for mouse scrolling, with a single hand)**  
  To activate:
  - Hold <kbd>Enter</kbd>
  - Tap <kbd>Shift</kbd> + <kbd>Enter</kbd> will `Toggle Layer 3`

## Usage
- Space Cadet  
  - <kbd>\*Shift (</kbd> and <kbd>Shift\* )</kbd>
- Key Override
  - <kbd>Shift</kbd> + <kbd>Backspace</kbd> as <kbd>Delete</kbd>.
  - <kbd>CMD</kbd> + <kbd>Esc</kbd> as <kbd>CMD</kbd> + <kbd>`</kbd>, to <code>Switch among App windows</code> on macOS.
  - <kbd>Ctrl</kbd> + <kbd>Esc</kbd> to output char <code>`</code>
  - <kbd>Shift</kbd> + <kbd>Esc</kbd> to output char `~`
- Combo Keys
  - <kbd>K</kbd> + <kbd>J</kbd> to produce `[`, also while holding <kbd>Shift</kbd> will produce `{`,  
  With <kbd>CMD</kbd> will produce a `Go Back`,  
  With <kbd>Shift</kbd> + <kbd>CMD</kbd> will `Switch to the left tab`.
  - <kbd>K</kbd> + <kbd>L</kbd> to produce `]`, also while holding <kbd>Shift</kbd> will produce `}`,  
  With <kbd>CMD</kbd> will produce a `Go Forward`,  
  With <kbd>Shift</kbd> + <kbd>CMD</kbd> will `Switch to the right tab`.
  - <kbd>Shift</kbd> + <kbd>TG(1)</kbd>, Hold to `Activate Layer 2`.
  - <kbd>Shift</kbd> + <kbd>Enter</kbd>, Tap to `Toggle Layer 3`.
- Tap Dance, <kbd>CMD</kbd> + <kbd>Q W E R T Y U I O P</kbd>
  - Single Tap will Trigger <kbd>CMD</kbd> + <kbd>1 2 3 4 5 6 7 8 9 0</kbd>.
  - Double Tap will Trigger the original commands.
  - Only 200ms of delays introduced while processing the above Shortcut keys.
  - No deleys while normally typing, or other Shortcut keys triggered.

