from flask import Blueprint, render_template

main = Blueprint('main', __name__)

@main.route('/')
def index():
    return 'hehe'

@main.route('/profile')
def profile():
    return 'profile'










# if __name__ == '__main__':
#     socketio.run(app, debug=True)