# Setup instructions

1. Use a fork of, or download, the [`Keychron/qmk_firmware:playground`](https://github.com/Tecsmith/qmk_firmware/tree/playground/) repo<i>:branch</i>.

2. If you're using a fork remember to never use the `master` branch, rather create a local branch.

    ```bash
    git branch ts-keychron-q1-r2
    git checkout ts-keychron-q1-r2
    ```

3. Create a submodule of this repo:

    ```bash
    git submodule add https://github.com/Tecsmith/keychron-q1-r2
    ```

4. Create a `custom` folder in the `keyboards` folder and use git to move *(and rename)* the submodule folder to there *(remember to rename the dashes {`-`} for underscores {`_`})*:

    ```bash
    mkdir keyboards/custom
    git mv keychron-q1-r2 keyboards/custom/keychron_q1_r2
    ```

5. You should be able to compile now:

    ```bash
    make custom/keychron_q1_r2:vinorodrigues
    ```